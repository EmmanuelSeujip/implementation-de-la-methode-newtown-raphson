# ─── Détection OS ────────────────────────────────────────────────────
ifeq ($(OS),Windows_NT)
    TARGET  = mon_evaluateur.exe
    RM      = del /f /q
    FIXPATH = $(subst /,\,$1)
else
    TARGET  = mon_evaluateur
    RM      = rm -f
    FIXPATH = $1
endif

# ─── Compilateur et flags ─────────────────────────────────────────────
CC     = gcc
CFLAGS = -Wall -g \
         -I. \
         -Iutils/type \
         -Iutils/tree \
         -Iparse/function \
         -Iparse/intervalle \
         -Iblackbox/calcul/calcul_dual \
         -Iblackbox/calcul/dual \
         -Iblackbox/calcul/eval \
         -Iblackbox/methods/newton \
         -Iblackbox/methods/trapeze \
         -Iblackbox/methods/simpson
LIBS   = -lm

# ─── Fichiers générés par Bison et Flex ──────────────────────────────
BISON_OUT_FUNC  = parse/function/parser.tab.c
BISON_OUT_INTER = parse/intervalle/parser_interval.tab.c
FLEX_OUT_FUNC   = parse/function/lex.yy.c
FLEX_OUT_INTER  = parse/intervalle/lex.interval_.c

# ─── Sources ──────────────────────────────────────────────────────────
SRCS = main.c \
       utils/tree/tree.c \
       blackbox/calcul/calcul_dual/calcul.c \
       blackbox/calcul/dual/dual.c \
       blackbox/calcul/eval/evaluer.c \
       blackbox/methods/newton/newton.c \
       blackbox/methods/trapeze/trapeze.c \
       blackbox/methods/simpson/simpson.c \
       $(BISON_OUT_FUNC) \
       $(BISON_OUT_INTER) \
       $(FLEX_OUT_FUNC) \
       $(FLEX_OUT_INTER)

OBJS = $(SRCS:.c=.o)

# ─── Règle principale ─────────────────────────────────────────────────
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

# ─── Génération Bison ─────────────────────────────────────────────────
parse/function/parser.tab.c parse/function/parser.tab.h: parse/function/parser.y
	bison -d -o parse/function/parser.tab.c parse/function/parser.y

parse/intervalle/parser_interval.tab.c parse/intervalle/parser_interval.tab.h: parse/intervalle/parser_interval.y
	bison -d -o parse/intervalle/parser_interval.tab.c parse/intervalle/parser_interval.y

# ─── Génération Flex ──────────────────────────────────────────────────
parse/function/lex.yy.c: parse/function/lexer.l parse/function/parser.tab.h
	flex -o parse/function/lex.yy.c parse/function/lexer.l

parse/intervalle/lex.interval_.c: parse/intervalle/lexer_interval.l parse/intervalle/parser_interval.tab.h
	flex -o parse/intervalle/lex.interval_.c parse/intervalle/lexer_interval.l

# ─── Compilation .c → .o ──────────────────────────────────────────────
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ─── Nettoyage ────────────────────────────────────────────────────────
clean:
	$(RM) $(call FIXPATH, \
	    $(OBJS) \
	    $(TARGET) \
	    parse/function/parser.tab.c \
	    parse/function/parser.tab.h \
	    parse/function/lex.yy.c \
	    parse/intervalle/parser_interval.tab.c \
	    parse/intervalle/parser_interval.tab.h \
	    parse/intervalle/lex.interval_.c)

.PHONY: all clean