all: cli ser

prepare:
	rpcgen cbcast.x	

cli: cbcast_client.c cbcast_clnt.c
	gcc -Wall -o cli cbcast_client.c cbcast_clnt.c

ser: cbcast_server.c cbcast_svc.c cbcast_clnt.c
	gcc -Wall -o ser cbcast_server.c cbcast_svc.c cbcast_clnt.c -pthread
	
clean:
	rm -rf cli ser

distclean: clean
	rm -rf cbcast.h cbcast_clnt.c cbcast_svc.c