import java.util.*;
class Solution {
    public int[] solution(int[] fees, String[] records) {
        Map<String, ParkingInfo> parkingInfoMap = new HashMap<>();
        for (String record : records) {
            String[] parkingData = record.split(" ");

            int time = Integer.parseInt(parkingData[0].split(":")[0]) * 60;
            time += Integer.parseInt(parkingData[0].split(":")[1]);
            String carNum = parkingData[1];
            String breakDown = parkingData[2];

            if (!parkingInfoMap.containsKey(carNum)) {
                ParkingInfo parkingInfo = new ParkingInfo(time, carNum, breakDown);
                parkingInfoMap.put(carNum, parkingInfo);
            }
            else {
                ParkingInfo parkingInfo = parkingInfoMap.get(carNum);
                parkingInfo.parkingInOut(time,breakDown);
            }
        }

        List<String> sortKey = new ArrayList<>(parkingInfoMap.keySet());
        Collections.sort(sortKey);
        List<Integer> chargeList = new ArrayList<>();

        for (String key : sortKey) {
            chargeList.add(parkingInfoMap.get(key).totalCal(fees));
        }

        return chargeList.stream().mapToInt(Integer::intValue).toArray();
    }

    public static class ParkingInfo {
        int time;
        String carNum;
        String status = "NONE";
        int parkingTime = 0;

        public String getStatus() {
            return status;
        }

        public ParkingInfo(int time, String carNum, String status) {
            this.time = time;
            this.carNum = carNum;
            this.status = status;
        }

        public void parkingInOut(int time, String check) {
            if (check.equals("IN")) {
                this.time = time;
            } else {
                parkingTime += time - this.time;
            }
            status = check;
        }

        public int totalCal(int[] fees) {
            int basicTime = fees[0];
            int charge = fees[1];
            long unitTime = fees[2];
            int unitCharge = fees[3];

            if (Objects.equals(status, "IN")) {
                parkingTime += ((23*60)+59) - time;
                status = "OUT";
            }
            if (parkingTime > basicTime) {
                charge += Math.ceil((parkingTime - basicTime) / (unitTime + 0.0)) * unitCharge;
            }

            return charge;
        }
    }
}