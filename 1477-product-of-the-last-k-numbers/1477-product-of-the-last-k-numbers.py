class ProductOfNumbers:

    def __init__(self):
        self.v=[1]
        self.size=0
        pass

        

    def add(self, num: int) -> None:
        if num==0:
            self.v=[1]
            self.size=0
        else:
            self.v.append(self.v[self.size]*num)
            self.size+=1
        
        

    def getProduct(self, k: int) -> int:
        if k>self.size:
            return 0
        return int(self.v[self.size] / self.v[self.size-k])
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)