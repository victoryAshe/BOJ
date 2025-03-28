num = input()
length = len(num)

# 한 자리 수 인 경우 처리
if(int(num)//10) < 1:
  if(int(num)==9) :
    result = str(11) # 9보다 크면서 가장 작은 Palindrome 11
  else:
    result = str(int(num)+1) # 그 외 한 자리 수의 경우 +1

else:
  # 중앙을 기준으로 앞쪽 절반을 뒤집어, 뒤쪽에 붙였을 때 비교
  if int(num[:length//2][::-1]) > int(num[length//2 + length%2::]):
    # 앞쪽 절반을 뒤집은 것이 뒤쪽 절반보다 크면 그대로 Palindrome 생성
    result = num[:length//2+length%2] + num[:length//2][::-1]
  else:
    # 그렇지 않으면 가운데 부분을 1 증가 시키고 Palindrome 생성
    num = str(int(num[:length//2 + length%2]) +1)
    num += num[length//2-1 ::-1]
    result = num

print(result) # 결과 출력