#!/usr/bin/python3
# This Python file uses the following encoding: utf-8

"""
This module contains the functions that relate to the first three
lectures of the course (basic training and lists). 
"""
def speed(dist, time):
    """Print the speed of travel.

    Calculates the speed of travel 
    Given a distance (dist) and time (time).

    You should round the result to ONE decimal 
    places (use the round method, for example 
    round(10.01,1) creates the output 10.0). 

    Why do this? To hide any problems related to 
    floating point precision that would make automated
    testing harder.

    Args:
       dist is a float
       time is an int
    """

    sp = dist/time
    return (round(sp,1))

def pythagoras(a, b):
    """Find the length of a third side of a triangle.

    Uses pythagoras' theorem to calculate the length, that is the sum
    of the squares of two legs (a and b) is equal to the sum of the
    squares of the other leg.

    If a and b are both equal or greater than zero, print
    the length of the leg.

    If a is zero or negative print "First leg is invalid"

    If b is zero or negative print "Second leg is invalid"

    Again you should round the output to one decimal place (hide
    precision problems).

    Args:
       a is an integer or float
       b is an integer or float

    """
    # validate the arguments and print an error if either is wrong

    if (a>0 and b>0):
        c = (a**2 + b**2)**(.5)
        return (round(c,1))
    elif (a <=0):
        print ('First leg is invalid')
    elif (b <=0):
        print ('Second leg is invalid')
    


def grade(mark, mcr):
    """Assign a letter grade based on a mark

    Implement this grading scheme.

    A between 80 and 100
    B between 65 and 79
    C between 50 and 65
    D between 40 and 49
    E between 0 and 39

    K Fail due to not satisfying mandatory course requirements, even
      though the student’s numerical course mark reached the level
      specified for a pass, usually 50%. A student whose course mark
      is below 50 should be given a D (40–49) or E (0 –39), regardless
      of whether they met the mandatory course requirements.

    You should sanity check the types of the inputs.

    Args: 
       mark is an integer mark, if not integer print "Invalid mark"

       mcr is a boolean (True if met mandatory requirements, False
        if have not met them), if not boolean print "Invalid mcr"

    """
    # sanity check arguments
    if type(mark) != int:
        print('Invalid mark')
    elif type(mcr) != bool:
        print('Invalid mcr')
    elif mcr == False:
        print('K')
    elif mark >= 0 and mark <= 100:
        if mark >= 80:
            print('A')
        elif mark >= 65 and mark < 80:
            print('B')
        elif mark >= 50 and mark < 65:
            print('C')
        elif mark >= 40 and mark < 50:
            print('D')
        elif mark >= 0 and mark < 40:
            print('E')


def count_after(text, marker):
    """
    given a list of text and a word marker, display the number of words
    in the list after the marker (e.g. if the list is:
    ['one', 'two', 'three', 'four'] and the marker is 'two', then print 2.

    Print the length of the entire list of words if the marker is not
    in the list.
    
    You should check the arguments and print an error message if the
    types of the argument are different from expected.

    For example, if the text is not a list display "Expected a list of
    words" and if the marker is not string display "Expected a string".

    Args:
      text is a list of words
      marker is a string
    """
    # sanity check the arguments
    if type(marker) != str:
        print('Expected a string')
    elif type(text) != list:
        print("Expected a list of words")
    elif marker == "":
        print(len(text))
    elif not text:
        print(0)
    elif marker in text:
        num = len(text)
        x = text.index(marker)
        print(num - x -1)
    
   



