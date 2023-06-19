//
// Created by Irimieş Vasile on 6/19/2023.
//

#ifndef IRIMIES_VASILE_EMILIAN_REPOSTUDENTI_H
#define IRIMIES_VASILE_EMILIAN_REPOSTUDENTI_H
#include <vector>
#include "../Domain/Student.h"
using std::vector;


class RepoStudenti {

private:

    vector<Student> repo_studenti;
    string nume_fisier;

    /**
     * Incarca datele din fisier
     */
    void load_from_file();

    /**
     * Incarca datele in fisier
     */
    void store_to_file();

public:

    /**
     * Constructorul clasei RepoStudenti
     * @param nume_fisier string
     */
    RepoStudenti(string nume_fisier):nume_fisier{nume_fisier}{
        load_from_file();
    }

    /**
     * Sterge un student din lista de studenti
     * @param id - int
     */
    void sterge_student_dupa_id_repo(int id);

    /**
     * Modifica datele unui student
     * @param student_nou Student
     */
    void modifica_student_repo(Student student_nou);

    /**
     * Returneaza lista de studenti
     * @return vector<Student>
     */
    vector<Student> get_all()const;

    /**
     * Returneaza numarul de studenti
     * @return int
     */
    int len()const;

    /**
     * Adauga un student in lista
     * @param student Student
     */
    void adauga_student_repo(Student student);
};


#endif //IRIMIES_VASILE_EMILIAN_REPOSTUDENTI_H
