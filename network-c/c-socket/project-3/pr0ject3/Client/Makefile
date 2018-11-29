CC			= gcc
CFLAGS		= -Wall
LDFALGS		=
OBJFILES	= client.o
TARGET		= client

all:	$(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFALGS)

clean:
	rm -f $(OBJFILES) $(TARGET)