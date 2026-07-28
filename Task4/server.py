"""
ST5004CEM Operating Systems and Security
Task 4 - TCP Server

Author: Trisha Rajbanshi
"""

import socket

HOST = "127.0.0.1"
PORT = 5000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((HOST, PORT))

server.listen(1)

print("=" * 50)
print("SERVER STARTED")
print("=" * 50)
print(f"Listening on {HOST}:{PORT}")

connection, address = server.accept()

print(f"\nClient Connected: {address}")

message = connection.recv(1024).decode()

print("Client:", message)

connection.send("Message received successfully.".encode())

connection.close()

server.close()
