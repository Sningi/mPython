import sys
import shelve


def store_per(db):
    """

    Query user for data and store it in the shelf object
    """

    pid = input("enter un ID:")
    person = {}
    person['name'] = input('enter name: ')
    person['age'] = input('enter age: ')
    person['phone'] = input('enter phone number: ')

    db[pid] = person


def lookup_per(db):
    """
    Query user for ID and 
    """

    pid = input('enter ID number: ')
    field = input('what would you like to know ?(name.age,phone)')
    field = field.strip().lower()
    print(field.capitalize()+':', db[pid][field])


def print_help():
    print('available com are:')
    print('store   : Store info about a person')
    print('lookup : Looks up a person from ID number')
    print('quit     : Save changes and exit')
    print('?            : Print this message')


def enter_com():
    cmd = input('enter com (? for help): ')
    cmd = cmd.strip().lower()
    return cmd


def main():
    database = shelve.open('./database.txt')
    try:
        while True:
            cmd = enter_com()
            if cmd == 'store':
                store_per(database)
            elif cmd == 'lookup':
                lookup_per(database)
            elif cmd == '?':
                print_help()
            elif cmd == 'quit':
                return
    finally:
        database.close()


if __name__ == '__main__':
    main()
