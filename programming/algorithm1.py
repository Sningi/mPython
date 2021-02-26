from algorithms import sorting as qs
str1 = "hello xiao lao di"
str2 = "xiao lao di hello"
str1 = qs.sort(str1)
str2 = qs.sort(str2)
if str1 == str2:
    print("ture")
