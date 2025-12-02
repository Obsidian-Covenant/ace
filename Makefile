CFLAGS ?= -g -ggdb
CFLAGS  += -I/usr/include/tirpc
LDFLAGS ?=
LIBS = -lpthread -lpcap

ace: tftp_client.o http_handler.o http_packet.o directory_parser.o xml_config_parser.o dhcpconfig.o arp.o buildmsg.o cache.o client.o peekfd.o signals.o udpipgen.o voiphop.o main.o
	gcc $(CFLAGS) $(LDFLAGS) -o ace \
		tftp_client.o http_handler.o http_packet.o directory_parser.o xml_config_parser.o \
		dhcpconfig.o arp.o buildmsg.o cache.o client.o peekfd.o signals.o udpipgen.o voiphop.o main.o \
		$(LIBS)

tftp_client.o: tftp_client.c
	gcc $(CFLAGS) -c tftp_client.c
http_handler.o: http_handler.c
	gcc $(CFLAGS) -c http_handler.c
http_packet.o: http_packet.c
	gcc $(CFLAGS) -c http_packet.c
directory_parser.o: directory_parser.c
	gcc $(CFLAGS) -c directory_parser.c
xml_config_parser.o: xml_config_parser.c
	gcc $(CFLAGS) -c xml_config_parser.c
dhcpconfig.o: dhcpconfig.c
	gcc $(CFLAGS) -c dhcpconfig.c
arp.o: arp.c
	gcc $(CFLAGS) -c arp.c
buildmsg.o: buildmsg.c
	gcc $(CFLAGS) -c buildmsg.c
cache.o: cache.c
	gcc $(CFLAGS) -c cache.c
client.o: client.c
	gcc $(CFLAGS) -c client.c
peekfd.o: peekfd.c
	gcc $(CFLAGS) -c peekfd.c
signals.o: signals.c
	gcc $(CFLAGS) -c signals.c
udpipgen.o: udpipgen.c
	gcc $(CFLAGS) -c udpipgen.c
voiphop.o: voiphop.c voiphop.h
	gcc $(CFLAGS) -c voiphop.c
main.o: main.c
	gcc $(CFLAGS) -c main.c

clean:
	rm -f *.o
	rm -f ace
