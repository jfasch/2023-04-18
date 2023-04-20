class Sensor:
    def __init__(self, temp):
        self.temp = temp
    def get_temperature(self):
        return self.temp

s1 = Sensor(42)
