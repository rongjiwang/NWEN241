"""
Name: Wang Rong, ID: 300139010
"""
import csv
def add_vectors(vector_1, vector_2):
    """Returns a list object representing the result of adding two vectors together.

       Arguments:
       vector_1 -- list representing first vector
       vector_2 -- list representing second vector

       Error checking:
       Both arguments must be of type list.
       Both vectors must of the same length.
       Only vector elements of type int can be added together.
    """
    t = []
    if type(vector_1) != list and type(vector_2) != list:
        print("Error: first argument is not a list")
        print("Error: second argument is not a list")
        return None
    if type(vector_1) != list:
        print("Error: first argument is not a list")
        return None
    if type(vector_2) != list:
        print("Error: second argument is not a list")
        return None
    if len(vector_1) != len(vector_2):
        print("Error: lengths of the two vectors are different")
        return None
    for (a,b) in zip(vector_1, vector_2):
        if((type(a) != int) | (type(a) != type(b))):
            print("Error: attempted to add incompatible %s to %s" % (a,b))
            return None
        t.append(a+b)
    return t
    
    

def print_frequency(some_text):
    """Prints a table of letter frequencies within a string. 

       Non-letter characters are ignored (use .isalpha()).
       Table is sorted alphabetically.
       Letter case is ignored.
       Two blank spaces will separate the letter from its count.

       Returns None in all cases.

       Argument:
       some_text -- string containing the text to be analysed.

       Error checking:
       The argument must be a string object.
    """
    if some_text == None:
        print("Error: only accepts strings")
        return None
    if type(some_text) != str:
        print("Error: only accepts strings")
        return None
    t=[]
    temp = some_text.lower()
    for s in temp:
        if s.isalpha():
            t.append(s)
    if t == []:
        return None
    t.sort()

    count = 0
    char = t[0]

    for c in t:
        if char ==c:
            count+=1
        else:
            print ("%s  %s" % (char, count))
            char = c
            count =1
    print ("%s  %s" % (char,count))


def verbing(some_text):
    """Returns a string where the each word has ing added to it if it is 3 or more characters or length and 
       ly to shorter words.

       Argument:
       some_text -- string containing the text to be analysed.

       Error checking:
       The argument must be a string object.
    """
    if some_text == None:
        print ("Error: only accepts strings")
        return None
    if type(some_text)!= str:
        print ("Error: only accepts strings")
        return None
    if some_text == "":
        return ''
    my_list = some_text.split(" ")

    temp = []
    for s in my_list:
        if len(s) >= 3:
            temp.append(s+"ing")
        else:
            temp.append(s+"ly")
    string = " ".join(temp)
    
    return ''+ string +''
    
   

def add_vectors_file(file_name):
    """
    Processes a given comma seperated file and extracts the 'pay' and 'bonus' columns
    then adds the two vectors together to determine the total price.

    Argument:
    file_name -- the name of the file (assumed to exist in the same directory as the 
                 python script is executed). The file is a set of comma seperated values
                 the first line contains headers (seperated by commas) and subsequent lines
                 contain data corrosponding to each header.

    Error checking:
    The argument must be a string object
    The file must exist and be readable (no need to distinguish these cases)
    The 'pay' and 'bonus' columns must exist in the header

    """
    if type(file_name) != str:
        print("Error: only accepts strings")
        return None
    if not file_name.endswith('.csv'):
        print("Error reading from file notafile.txt")
        return None
    t = []
    try:
        f = open(file_name, 'r')
    except IOError:
        print("Can't read this file")
        sys.exit()
    with f:
        reader = csv.DictReader(f)

        for row in reader:
            if ('pay' in row and 'bonus' in row):
                t.append(int(row.get('pay'))+(int(row.get('bonus'))))
            else:
                print ("Error: the file must contain pay and bonus columns")
                return None
        return t

    
