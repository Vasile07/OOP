//
// Created by Irimieş Vasile on 6/19/2023.
//

#ifndef IRIMIES_VASILE_EMILIAN_SERIVCESTUDENTI_H
#define IRIMIES_VASILE_EMILIAN_SERIVCESTUDENTI_H
#include "../Persistance/RepoStudenti.h"

class SerivceStudenti {

private:

    RepoStudenti repo;

public:

    /**
     * Constructor ServiceStudenti
     * @param repo RepoStudenti
     */
    SerivceStudenti(RepoStudenti repo):repo{repo}{}

    /**
     * Intinereste toti studentii din lista
     */
    void intinerire();

    /**
     * Imbatraneste toti studentii din lista
     */
    void imbatranire();

    /**
     * Sterge studentul cu numarul matricol dat
     * @param numar_matricol int
     */
    void sterge_student_dupa_id(int numar_matricol);

    /**
     * REturneaza lista de studenti
     * @return vector<Student>
     */
    vector<Student> get_all()const;

    /**
     * Returneaza numarul de studenti
     * @return int
     */
    int len();

    /**
     * Adauga studentul in lista
     * @param student Student
     */
    void adauga_student(Student student){
        repo.adauga_student_repo(student);
    }

    /**
     * Cauta un student cu numarul matricol dat in lista
     * @param nr int
     * @return Student
     */
    Student cauta_student_numar_matricol(int nr){
        for(Student student : repo.get_all())
            if(student.get_numar_matricol() == nr)
                return student;
    }
};


#endif //IRIMIES_VASILE_EMILIAN_SERIVCESTUDENTI_H
