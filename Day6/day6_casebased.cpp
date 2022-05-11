#include <iostream>
static int obj_count = 0;
//-------------------- Age Not With in Range Exception --------------------
class AgeNotWithinRangeException : public std::exception {
    const char *msg;
    public:
    AgeNotWithinRangeException(const char *s) : msg(s) {}
    virtual const char* what() const throw()
    {
        return msg ;
    }
};
//-------------------- Name Not Valid Exception --------------------
class NameNotValidException : public std::exception {
    const char *msg;
    public:
    NameNotValidException(const char *s) : msg(s) {}
    virtual const char* what() const throw()
    {
        return msg ;
    }
};

//-------------------- Invalid Courses Exception --------------------
class InvalidCoursesException : public std::exception {
    const char *msg;
    public:
    InvalidCoursesException(const char *s) : msg(s) {}
    virtual const char* what() const throw()
    {
        return msg ;
    }
};

//-------------------- object count exception --------------------
class obj_count_exception : public std::exception {
    const char *msg;
    public:
    obj_count_exception(const char *s) : msg(s) {}
    virtual const char* what() const throw()
    {
        return msg ;
    }
};

//-------------------- student --------------------
class student {
public:
    int rno,age;
    std::string name,course;
    std::string courses_available[3]={"c++","java","python"};
    student(int rno, std::string name, int age, std::string course) 
        : rno(rno), name(name), age(age), course(course){
        obj_count++;
            if(obj_count>1)
                throw obj_count_exception("\nDont try to create more than one object of student class");
    }
    /* 1 */
    void age_range(){
        if(age < 15 || age > 21){
            throw AgeNotWithinRangeException("Age is not within range");
        }
    }
    /* 2 */
    void name_validity(){
        for(int i=0;i<name.size();i++){
            if(!isalpha(name[i])){
                throw NameNotValidException("Name is not valid");
            }
        }
    }
    /* 3 */
    void courses_validity(){
        for(int i=0;i<course.size();i++){ //converting courses to lower case
            course[i]=tolower(course[i]);
        }
        bool flag = false;
        for(int i=0;i<3;i++){ //checking if course is valid
            if(course == courses_available[i]){
                flag=true;
                break;
            }
        }
        if(!flag){
            throw InvalidCoursesException("Invalid courses");
        }
    }
};

//-------------------- fucntion to handle exceptions --------------------
void checker(student s1){
     try{
        try{
            try{
                s1.name_validity();
            }
            catch(NameNotValidException &e){
                std::cout << e.what() << std::endl;
            }
            s1.age_range();
        }
        catch(AgeNotWithinRangeException &e){
            std::cout << e.what() << std::endl;
        }
        s1.courses_validity();
    }
    catch(InvalidCoursesException &e){
        std::cout << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Some exception caught" << std::endl;
    }
}

//-------------------- main --------------------
int main() {
    try{
        student s1(100,"Raj**",200,"jAvA"); //name exception
        checker(s1);
        /* Uncomment each( & commennt rest) to check different behaviours */

        // student s2(100,"Raj",20,"Python"); //works fine
        // checker(s2);

        // student s3(100,"Raj",200,"c++"); //age exception
        // checker(s3);

        student s4(100,"Raj",20,"javascript"); //courses exception
        checker(s4);
    }
    catch(obj_count_exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}