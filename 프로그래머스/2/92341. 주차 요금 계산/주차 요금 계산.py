from collections import defaultdict
import math

def solution(fees, records):
    parking_info_map = defaultdict(ParkingInfo)

    for record in records:
        parking_data = record.split(" ")

        time = int(parking_data[0].split(":")[0]) * 60
        time += int(parking_data[0].split(":")[1])
        car_num = parking_data[1]
        breakdown = parking_data[2]

        if car_num not in parking_info_map:
            parking_info = ParkingInfo(time, car_num, breakdown)
            parking_info_map[car_num] = parking_info
        else:
            parking_info = parking_info_map[car_num]
            parking_info.parking_in_out(time, breakdown)

    sort_key = sorted(parking_info_map.keys())
    charge_list = [parking_info_map[key].total_cal(fees) for key in sort_key]

    return charge_list

class ParkingInfo:
    def __init__(self, time, car_num, status):
        self.time = time
        self.car_num = car_num
        self.status = status
        self.parking_time = 0

    def parking_in_out(self, time, check):
        if check == "IN":
            self.time = time
        else:
            self.parking_time += time - self.time
        self.status = check

    def total_cal(self, fees):
        basic_time, charge, unit_time, unit_charge = fees

        if self.status == "IN":
            self.parking_time += ((23 * 60) + 59) - self.time
            self.status = "OUT"

        if self.parking_time > basic_time:
            charge += math.ceil((self.parking_time - basic_time) / unit_time) * unit_charge

        return charge