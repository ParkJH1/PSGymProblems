# 자릿값

##### 시간제한 1초, 메모리 제한 128MB

## 문제

자릿값이란 어떤 수의 자릿수가 실제로 나타내는 값을 말한다.

예를 들어 1204에서 넷째 자릿수인 1이 실제로 나타내는 값은 1000이고, 둘째 자릿수인 0이 실제로 나타내는 값은 0이다.

자연수 N이 주어졌을 때, N의 각 자릿수의 자릿값을 구하여라.



## 입력

입력은 여러 개의 테스트 케이스로 주어진다. 첫 번째 줄에 테스트 데이터의 수 T(1 ≤ T ≤ 10,000)가 주어진다. 각 테스트 데이터의 첫 번째 줄에는 자연수 N(1 ≤ N ≤ 10,000)이 주어진다.



## 출력

각 테스트 케이스의 첫 번째 줄에 높은 자릿수의 자릿값부터 차례대로 공백으로 구분하여 출력한다.



## 예제 입력 1

```
5
5009
7
9876
10000
10
```



## 예제 출력 1

```
5000 0 0 9
7 
9000 800 70 6
10000 0 0 0 0
10 0
```


