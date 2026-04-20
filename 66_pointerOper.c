// emp[0].name === (ptr + 0)->name === ptr->name
// emp[4].age === (ptr + 4)->age

// ++ptr->age === ++(ptr->age) :    ptr의 멤버 age의 값을 1증가
// (++ptr)->age + 50 :              다음 위치 구조체의 age항목을 가리킨다
//  ptr->age :                      ptr이 가리키고 있는 구조체의 age항목
// ptr++->age :                     p->age를 구하고 ptr를 1증가
// p->age++ :                       p->age의 값을 사용 후, 그 값을 1 증가 시킨다
// --p->age + 50 :                  p->age의 값을 1감소 시킨 후 50을 더한다