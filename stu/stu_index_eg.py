months=['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec']
endings=['st','nd','rd']+17*['th']+['st','nd','rd']+7*['th']+['st']
year=input()
month=input('month:')
day=input('day:')
month_num=int(month)
daynum=int(day)
monthname=months[month_num-1]
ordinal=day+endings[daynum-1]
print (monthname+' '+ordinal+','+year)
