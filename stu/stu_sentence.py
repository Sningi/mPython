sen=input("please input sentence:")

scr_width=80
text_width=len(sen)
box_width=text_width+6
left_margin=(scr_width-box_width)//2

print()
print(' '*left_margin+'+'+'-'*(box_width-6)+'+')
print(' '*left_margin+'|'+' '*text_width   +'|')
print(' '*left_margin+'|'+       sen       +'|')
print(' '*left_margin+'|'+' '*text_width   +'|')
print(' '*left_margin+'+'+'-'*(box_width-6)+'+')
print()
