def is_leap(year):
    leap = True
    
    # Write your logic here
    if year%4 == 0:
        if year%100 == 0:
            if year%400 == 0:
                return leap
            else:
                return (not leap)
        else:
            return leap
    else:
        return (not leap)