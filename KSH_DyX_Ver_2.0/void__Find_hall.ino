void Find_hall(){
  const char *log;
//===================
// Defalut 각도 설정
//===================
  dxl_wb.goalPosition(id_list[0], (int32_t)Degree(180)); //goal position -> 첫번째 변수 : 아이디, 뒤는 0~4095 (시형은 다시 각도를 함수화함)
  dxl_wb.goalPosition(id_list[1], (int32_t)Degree(180)); //same
  //초기상태 지정....//
 
  move_horn(0,180,1000,&log);   //2축을 움직이기 위해 사용한 함수(따로 선언)
  move_horn(1,300,3000,&log);

//===================
// 차량 왼쪽 scan
//===================
  dxl_wb.goalPosition(id_list[0], (int32_t)Degree(240)); //왼쪽으로 1번 1축 move
  delay(1000);   

  dxl_wb.goalPosition(id_list[1], (int32_t)Degree(90));
  delay(1000);

  move_horn(0,240,1000,&log);
  move_horn(1,270,500,&log);
  
  dxl_wb.jointMode(id_list_2horn[1], 0, 0, &log);
  dxl_wb.goalPosition(id_list_2horn[1], (int32_t)Degree(270));
  delay(500);
  for(int i =0 ; i<60; i++){
    dxl_wb.goalPosition(id_list_2horn[1], (int32_t)Degree(270-i));
    delay(100);
  }
  delay(1000);

  dxl_wb.goalPosition(id_list_2horn[1], (int32_t)Degree(300));
  delay(1000);
  dxl_wb.itemWrite(id_list_2horn[1], "Torque_Enable", 0, &log);

  move_horn(0,180,1000,&log);

  dxl_wb.goalPosition(id_list[1], (int32_t)Degree(180));
  delay(500);

//===================
// 차량 오른쪽 scan
//===================  
  dxl_wb.goalPosition(id_list[0], (int32_t)Degree(120));
  delay(1000);
  
  dxl_wb.goalPosition(id_list[1], (int32_t)Degree(90));
  delay(1000);

  move_horn(0,240,1000,&log);

  dxl_wb.jointMode(id_list_2horn[1], 0, 0, &log);
  dxl_wb.goalPosition(id_list_2horn[1], (int32_t)Degree(270));
  delay(500);
  for(int i =0 ; i<60; i++){
    dxl_wb.goalPosition(id_list_2horn[1], (int32_t)Degree(270-i));
    delay(100);
  }
  delay(1000);
  dxl_wb.goalPosition(id_list_2horn[1], (int32_t)Degree(300));
  delay(1000);
  dxl_wb.itemWrite(id_list_2horn[1], "Torque_Enable", 0, &log);

  move_horn(0,180,1000,&log);
}
