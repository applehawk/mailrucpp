/* 
   
 */

#ifndef _Employee_hh_
#define _Employee_hh_

class Employee {

  protected:
    MoneyAmount salary;
    Account salary_account;
    double bonus_coefficient;


  public:
    void pay_salary(double bonus_coefficient);
    void pay_salary();


};

#endif /* _Employee_hh_ */

