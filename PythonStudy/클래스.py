class FourCal:
    # 생성자
    def __init__(self, first, second):
        self.first = first
        self.second = second

    def seltdata(self, first, second):
        self.first = first
        self.second = second

    def add(self):
        result = self.first + self.second
        return result

    def sub(self):
        result = self.first - self.second
        return result

    def mul(self):
        result = self.first * self.second
        return result

    def div(self):
        result = self.first / self.second
        return result

a = FourCal(4,2)
a.add()
a.mul()
a.sub()
a.div()

class Rectangle:
    count = 0 # 클래스 변수

    def __init__(self, width, height):
        self.width = width
        self.height = height
        Rectangle.count += 1

    # 인스턴스 매서드
    def calcArea(self):
        area = self.width * self.height
        return area

    # 정적 메서드
    @staticmethod
    def isSquare(rectWidth, rectHeight):
        return rectWidth == rectHeight

    # 클래스 메서드
    '''
        정적 메서드랑 비슷핮지만 self대신 cls라는 파라미터를 전달 받아
        클래스 변수 등을 엑세스 가능
    '''
    @classmethod
    def printCount(cls):
        print(cls.count)

    # Special Method (Magic Method)
    '''
        __add__
        __sub__
        __cmp__
        __str__ 문자열로 객체를 표현할 때 사용
    '''
    def __add__(self, other):
        obj = Rectangle(self.width + other.width, self.height + other.height)
        return obj

# 테스트
square = Rectangle.isSquare(5,5)
print(square) # True

rect1 = Rectangle(5,5)
rect2 = Rectangle(2,5)
rect1.printCount() # 2

rect3 = rect1 + rect2 # __add__()가 호출됨