
import socket
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)

GPIO.setup(35, GPIO.OUT)
GPIO.setup(36, GPIO.OUT)
GPIO.setup(37, GPIO.OUT)
GPIO.setup(38, GPIO.OUT)

def create_socket():
    try:
        global s
        global host 
        global port 
    
        host =""
        port =7777

        s = socket.socket()

    except socket.error as msg:
        print(msg)

def bind_socket():
    try:
        global s
        global host 
        global port

        s.bind((host,port))
        s.listen(5)

    except socket.error as msg:
        print(msg)
        bind_socket()

def accept_socket():
    conn, addr = s.accept()
    print("Connection Success !")
    get_cmmds(conn)

def front():
    print("Received --Front Command !")
    GPIO.output(35,True)
    GPIO.output(36,False)
    GPIO.output(37,False)
    GPIO.output(38,False)

def back():
    print("Received --Back Command !")
    GPIO.output(35,False)
    GPIO.output(36,True)
    GPIO.output(37,False)
    GPIO.output(38,False)


def left():
    print("Received --Left Command !")
    GPIO.output(35,False)
    GPIO.output(36,False)
    GPIO.output(37,True)
    GPIO.output(38,False)

def right():
    print("Received --Right Command !")
    GPIO.output(35,False)
    GPIO.output(36,False)
    GPIO.output(37,False)
    GPIO.output(38,True)

def stop():
    print("Received --Stop Command !")
    GPIO.output(35,False)
    GPIO.output(36,False)
    GPIO.output(37,False)
    GPIO.output(38,False)



def main():
    create_socket()
    bind_socket()
    accept_socket()

def disconnect():
    global s
    s.shutdown(socket.SHUT_RDWR)
    s.close()

    main()

def main():
    create_socket()
    bind_socket()
    accept_socket()



def get_cmmds(conn):

    data = conn.recv(1024)

    if data == b'front\n':
        front()
        get_cmmds(conn)
    elif data == b'stop\n':
        stop()
        get_cmmds(conn)
    elif data == b'back\n':
        back()
        get_cmmds(conn)
    elif data == b'left\n':
        left()
        get_cmmds(conn)
    elif data == b'right\n':
        right()
        get_cmmds(conn)
    elif data == b'd\n':
        disconnect()

main()
