mac: cli_mac ser_mac
linux: cli_linux ser_linux

prepare:
	rpcgen cbcast.x	

cli_linux: cbcast_client.c cbcast_clnt.c cbcast_xdr.c
	gcc -Wall -o cli_linux cbcast_client.c cbcast_clnt.c cbcast_xdr.c

cli_mac: cbcast_client.c cbcast_clnt.c cbcast_xdr.c
	gcc -Wall -o cli_mac cbcast_client.c cbcast_clnt.c cbcast_xdr.c

ser_linux: cbcast_server.c cbcast_svc.c cbcast_clnt.c cbcast_xdr.c
	gcc -Wall -o ser_linux cbcast_server.c cbcast_svc.c cbcast_clnt.c cbcast_xdr.c -pthread

ser_mac: cbcast_server.c cbcast_svc.c cbcast_clnt.c cbcast_xdr.c
	gcc -Wall -o ser_mac cbcast_server.c cbcast_svc.c cbcast_clnt.c cbcast_xdr.c -pthread
	
clean:
	rm -rf cli_mac ser_mac cli_linux ser_linux

distclean: clean
	rm -rf cbcast.h cbcast_clnt.c cbcast_svc.c cbcast_xdr.c