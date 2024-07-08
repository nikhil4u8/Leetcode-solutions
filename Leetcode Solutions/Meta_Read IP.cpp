import socket

# Read IP addresses and ports from addresses.txt
with open('addresses.txt', 'r') as file:
    lines = file.readlines()

# Iterate through the lines and check host accessibility
for line in lines[1:]:  # Skip the header line
    parts = line.strip().split()
    if len(parts) == 2:
        ip, port = parts
        try:
            # Create a socket and attempt to connect to the host
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.settimeout(2)  # Adjust the timeout as needed
            result = sock.connect_ex((ip, int(port)))

            # Check if the host is reachable
            if result == 0:
                print(f"{ip}:{port} is reachable")
            else:
                print(f"{ip}:{port} is not reachable")

            # Close the socket
            sock.close()

        except Exception as e:
            print(f"Error checking {ip}:{port}: {e}")