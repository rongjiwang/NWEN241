import socket
import select


def run_server():
    """
    Start a server to facilitate the chat between clients.
    The server uses a single socket to accept incoming connections
    which are then added to a list (socket_list) and are listened to
    to recieve incoming messages. Messages are then stored in a database
    and are transmitted back out to the clients.
    """

    # Define where the server is running. 127.0.0.1 is the loopback address,
    # meaning it is running on the local machine.
    host = "127.0.0.1"
    port = 5005
    recv_buffer = 1024
    dic = {}
    current_username = ''

    # Create a socket for the server to listen for connecting clients
    server_socket = socket.socket()
    server_socket.bind((host, port))
    server_socket.listen(10)


    # Create a list to manage all of the sockets
    socket_list = []
    # Add the server socket to this list
    socket_list.append(server_socket)


    # Start listening for input from both the server socket and the clients
    while True:

        # Monitor all of the sockets in socket_list until something happens
        ready_to_read, ready_to_write, in_error = select.select(socket_list, [], [], 0)

        # When something happens, check each of the ready_to_read sockets
        for sock in ready_to_read:
            # A new connection request recieved
            if sock == server_socket:
                # Accept the new socket request
                sockfd, addr = server_socket.accept()
                # Add the socket to the list of sockets to monitor
                socket_list.append(sockfd)
                # Log what has happened on the server
                dic[sockfd] = addr[1]
                #current_username = addr[1]
                print ("Client (%s, %s) connected" % (addr[0],addr[1]))

            # A message from a client has been recieved
            else:
                try:
            #part1
                    recv_message = sock.recv(recv_buffer).decode().strip()
                    #valid message
                    if recv_message:
                        
                        #server printing
                        print (str(dic.get(sock)),": ",recv_message)
                        #send message back to client
                        #update our dictionary
                        if sock not in dic:
                            #first time visitor
                            send_string = "Server>>>Welcome to the server!"
                            sock.send(send_string.encode())
                            #update socket and default user name as unique ID number
                            #dic[sock] = sock.getpeername()[1]
                            #current_username = dic.get(sock)
                        #special command from client
                        #changing nick name for user
            #part 4
                        if recv_message.startswith('/NICK'):
                            nick_split = recv_message.split(" ")
                            print(nick_split)
                            if nick_split[0] == '/NICK' and len(nick_split)>1:
                                #current_username = nick_split[1]
                                dic[sock] = nick_split[1]
                                confirm_message = "You nick name has been changed!"
                                sock.send(confirm_message.encode())
                            else:
                                print ("Failed change nick for client",dic.get(sock))
                        #get a list of active user
                        elif recv_message.startswith('/WHO'):
                            for ss in dic:
                                user = str(ss.getpeername())+"/UserName: "+str(dic.get(ss))+"\n"
                                sock.send(user.encode())
                              
                            info = "\nActive user list has been given"
                            sock.send(info.encode())
                        #send a message to a named user
                        elif recv_message.startswith('/MSG'):
                            msg_split = recv_message.split(" ")
                            i=0
                            for sss in dic:
                                if msg_split[1] == dic.get(sss):
                                    personal_message = dic.get(sock)+": "+"".join(msg_split[2:])
                                    sss.send(personal_message.encode())
                                    i+=1
                            if i == 0:        
                                print("Person might not be in this room or offline")
                                
                                
            #part 3 other clients also receive a copy
                        else:
                            for s in socket_list:
                                if s != server_socket:
                                    temp = str(dic.get(sock))+": "+str(recv_message)
                                    s.send(temp.encode())
                    else:
                        print ("Client (%s, %s) is offline" % addr)
                        sock.close()
                        socket_list.remove(sock)
                        s = dic.pop(sock)
                        continue




                except:
                    print ("Client (%s, %s) is offline" % addr)
                    sock.close()
                    socket_list.remove(sock)
                    continue
                    
                # YOUR CODE HERE

                # Extract the data from the socket and iterate over the socket_list
                # to send the data to each of the connected clients.
    server_socket.close()


if __name__ == '__main__':
    run_server()
