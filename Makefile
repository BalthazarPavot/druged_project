
DEBUG			=		0

RM 				=		rm -f

CC				=		gcc

CFLAGS		+=	-Wextra -Wall -Werror -Wpedantic -Wshadow
CFLAGS		+=	-pedantic

LDFLAGS		+=	-lm
LDFLAGS		+=	-lglut -lGLU -lGL

BINDIR		=		bin
TARGET		=		main

SRCDIR		=		src
SRCS			=		$(addsuffix .c, event_handler ktree)

OBJS			=		$(SRCS:.c=.o)
GCH				=		$(SRCS:.c=.gch)


ifeq ($(DEBUG),1)
	CFLAGS	+=	-g
endif



all						:	$(TARGET)


$(TARGET)			:		$(addprefix $(BINDIR)/, $(OBJS))
			@echo building $(TARGET)
			$(CC) $@.c -o $(BINDIR)/$@ $? lib/* $(LDFLAGS) $(CFLAGS)


$(BINDIR)/%.o	:		$(SRCDIR)/%.c
			@echo compiling $(?)
			@$(CC) -c $? -o $@ $(CFLAGS) $(LDFLAGS)


clean	:
			@echo removing object files
			@$(RM) $(addprefix $(BINDIR)/,$(OBJS))
			@echo removing gch files
			@$(RM) $(addprefix $(SRCDIR)/,$(GCH))


fclean				:		clean
			@echo removing $(BINDIR)/$(TARGET)
			@$(RM) $(BINDIR)/$(TARGET)


re						:		fclean all


.PHONY				:		all clean fclean re

