# Time Conversion
"""
   12-hour AM/PM format -> military (24-hour) time으로 바꾸기

   hh:mm:ssAM or hh:mm:ssPM 
    o1 <= hh <= 12 and 00 <= mm,ss <= 59
    all input times are valid

    Midnight
    12:00:00AM -> 12-hour clock
    00:00:00 -> 24-hour clock
    Noon
    12:00:00PM -> 12-hour clock
    12:00:00 -> 24-hour clock

"""

time = input()
check = time[-2:]
time = time[:-2]

hh = int(time[:2])

if(check == "PM"):
    hh += 12
    if(hh == 24):
        hh -= 12
    time = ("%02d" % hh) + time[2:]

if(check == "AM"):
    if(hh == 12):
        hh -= 12
    time = ("%02d" % hh) + time[2:]

print(time)