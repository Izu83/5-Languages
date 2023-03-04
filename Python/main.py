import os

def clear():
    # For Window
    if os.name == 'nt':
        os.system('cls')
    # For Unix/Linux/MacOS
    else:
        os.sytem('clear')

def main():
    while True:
        print("1. Register\n2. Login")
        option = input()
        clear()

        if(option == '1'):
            username = input("Enter username: ")
            file_path = 'assets/' + username + '.txt'
            if os.path.exists(file_path):
                print("!-- There is a account with that name --!")
            else:
                file = open(file_path, 'w')
                file.write(username + '\n')
                file.write(input("Enter password: "))
                file.close()
        elif(option == '2'):
            username = input("Enter your username: ")
            file_path = 'assets/' + username + '.txt'
            if not os.path.exists(file_path):
                print("!-- This account doesnt exist --!")
            else:
                file = open(file_path, 'r')
                user = file.readline()
                a_password = file.readline()
                password = input("Enter your password: ")
                if password == a_password:
                    print("Hi, welcome to our program!")
                else:
                    print("!-- Not right password --!")
                file.close()


        elif(option == "2"):
            print("2")
        else:
            print("default")
            



main()