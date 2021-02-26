#__metaclass__=type
class Bird:
  def __init__(s):
    s.hug=True
  def eat(s):
    if s.hug:
      print("aaaaa")
      s.hug=False
    else:
      print("NO NO")
class sBird(Bird):
  def __init__(s):
    super(sBird,s).__init__()
    s.sou="sqaekk"
  def sing(s):
    print(s.sou)

while True:
  com=input("com\n")
  if not com:
    break
  else:
    exec(com)
