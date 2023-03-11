#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Patient;

class Doctor
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Patient>> m_patients{};

public:
    Doctor(std::string name): m_name{name} {}

    void addPatient(Patient& patient);
    friend std::ostream& operator<< (std::ostream& out, const Doctor& doctor);

    const std::string& getName() const{
        return m_name;
    }
};

class Patient
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Doctor>> m_doctors{};

    void addDoctor(const Doctor& doctor) {
        m_doctors.push_back(doctor);
    }

public:
    Patient(std::string name): m_name{name} {}
    // since this is a friend member function, I can now access the addDoctor function
    friend void Doctor::addPatient(Patient& patient);
    friend std::ostream& operator<< (std::ostream& out, const Patient& patient);

    const std::string& getName() const{
        return m_name;
    }
};

void Doctor::addPatient(Patient& patient) {
    m_patients.push_back(patient);
    patient.addDoctor(*this);
}

std::ostream& operator<< (std::ostream& out, const Doctor& doctor) {
    if(doctor.m_patients.empty()) {
        out << doctor.getName() << " has no patients ";
        return out;
    }

    out << doctor.getName() << " is seeing patients ";
    for(const auto& patient: doctor.m_patients)
        out << patient.get().getName() << " ";
    return out;
}

std::ostream& operator<< (std::ostream& out, const Patient& patient) {
    if(patient.m_doctors.empty()) {
        out << patient.getName() << " has no doctors ";
        return out;
    }

    out << patient.getName() << " is seeing ";
    for(const auto& doctor: patient.m_doctors)
        out << doctor.get().getName() << " ";
    return out;
}

int main() {
    Patient me{"kesavan"};
    Patient you{"dhanus"};

    Doctor him{"aravind"};
    Doctor she{"hailey"};

    him.addPatient(me);
    she.addPatient(you);
    she.addPatient(me);

    std::cout << him << '\n';
    std::cout << she << '\n';

    std::cout << me << '\n';
    std::cout << you << '\n';

    return 0;
}
