#pragma once

#pragma once

#include "pch.h"

class CLb
{
public:
    void mb(void);
};

class CLa

{
private:
    CLb b1; CLb* p1;
public:
    void ma1(void); void ma2(void); void ma3(CLb); void ma4(CLb&); void ma5(CLb*);
};