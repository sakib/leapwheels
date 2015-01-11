client: clean
  gcc client.c -o client
  ./client cheerios 51717
  
server: clean
  gcc server.c -o server
  ./server 51717

clean:
  rm -f client
  rm -f server
