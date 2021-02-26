class Tesi:
    value = 0

    def next(self):
        self.value += 1
        if self.value > 10:
            raise StopIteration
        return self.value

    def __iter__(self):
        return self


ti = Tesi()
for i in range(10):
    print(ti.next())
