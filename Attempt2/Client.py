import socket

s = socket.socket()
s.connect(("127.0.0.1", 9000))

print("conectado!")

data_total = ""

while len(data_total.split()) < 20:
    chunk = s.recv(1024)
    if not chunk:
        break
    data_total += chunk.decode()

s.close()

# convertir a números
valores = [float(x) for x in data_total.split()]

print("valores recibidos:")
for i, v in enumerate(valores):
    print(f"f({i}) = {v}")
