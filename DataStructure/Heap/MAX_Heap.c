insert(int num , int location)
  // location은 삽입할 위치 빈자리
  // num은 삽입 할 수
  int parentnode;

  while(location){

    parentnode <- (location -1)/2;

    if(num <= array[parentnode]) than
      array[location] <- num
      return;

    array[location] <- array[parentnode];
    location = parentnode;
  }
insert END


heap[];

delete(size)
  //size는 Heap의 크기를 나타넴
  if(size = 0)then // heap이 공백
  parent = 1 // root인덱스
  item <- heap[i]; // root를 삭제
  temp <- heap[size]; // 마지막 노드

  size <- size - 1 // 최종크기를 줄여줌
  while(parent <= size){
    i <- parent * 2 // 왼쪽 자식 노드
    if(heap[i] < heap[i+1])
    then i <- i+1 // 오른쪽 값이 더 클때

    if(temp >= heap[i]) then break;

    heap[parent] <- heap[i] // 자식을 위로 올림
    parent <- i
    i <- i*2
  }

  heap[parent <- temp]
  return item;

delete END
