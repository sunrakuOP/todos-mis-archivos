// manejar vectores de punteros a objetos propios
#include <iostream>
#include <vector>
#include <string>

class Medico{
private:
  std::string nombre, especialidad;
  int id;
  static int contador;
public:  
  Medico(const std::string& n, const std::string& e): nombre(n), especialidad(e), id(++contador) {}

  std::string getNombre() const { return nombre; }
  std::string getEspecialidad() const { return especialidad; }
  int getId() const { return id; }

  friend std::ostream& operator<<(std::ostream& os, const Medico& obj) {
    os << "Nombre: "<<obj.getNombre()<<"\nEspecialidad: " <<obj.getEspecialidad() 
      <<"\nId: "<<obj.getId() <<std::endl;
    return os;
  }
};
int Medico::contador=0;  // mostrar a que clase hace parte siempre

class Paciente{
private:
  std::string nombre;
  int edad, idP;
  static int contadorPaciente;
public:
  Paciente(const std::string& n, int e): nombre(n), edad(e), idP(++contadorPaciente){}

  std::string getNombre() const { return nombre; }
  int getEdad() const { return edad; }
  int getId() const { return idP; }

  friend std::ostream& operator<<(std::ostream& os, const Paciente& obj) {
    os<<"Nombre:" <<obj.getNombre()<<"\nEdad: "<<obj.getEdad()<<"\nId: "<<obj.getId()<<std::endl;
    return os;
  }

};
int Paciente::contadorPaciente = 0;

class Consulta{
private: // consulta no es duena del objeto, solo apunta a el
  Medico* medico;
  Paciente* paciente;
  std::string fecha, diagnostico;
public:
  Consulta(Medico& m, Paciente& p, const std::string& f, const std::string& d): medico(&m), paciente(&p), fecha(f), diagnostico(d) {}

  Medico* getMedico() const { return medico; }
  Paciente* getPaciente() const { return paciente; }

  friend std::ostream& operator<<(std::ostream& os, const Consulta& c) {
    os << "Médico:     " << c.medico->getNombre()   << "\n"
       << "Paciente:   " << c.paciente->getNombre() << "\n"
       << "Fecha:      " << c.fecha                 << "\n"
       << "Diagnóstico:" << c.diagnostico           << "\n";
    return os;
  }

};

int main() {
  Medico m1("Nicolas", "Internista");
  Medico m2("Laura", "Pediatria");
  Medico m3("Andres", "Cardiologia");

  Paciente p1("Juan", 20);
  Paciente p2("Camila", 35);
  Paciente p3("Sara", 28);
  Paciente p4("Tomas", 42);

  std::vector<Consulta> consultas;
  consultas.emplace_back(m1, p1, "2026-03-23", "Control general");
  consultas.emplace_back(m2, p2, "2026-03-24", "Gripe");
  consultas.emplace_back(m3, p3, "2026-03-24", "Dolor de pecho");
  consultas.emplace_back(m2, p4, "2026-03-25", "Chequeo pediatrico");
  consultas.emplace_back(m1, p3, "2026-03-26", "Revision de laboratorio");

  std::cout << "=== Todas las consultas ===\n";
  for (const Consulta& c : consultas) {
    std::cout << c << "\n";
  }

  const Medico& medicoBuscado = m2;
  std::cout << "=== Consultas del medico: " << medicoBuscado.getNombre() << " ===\n";
  bool encontroMedico = false;
  for (const Consulta& c : consultas) {
    if (c.getMedico()->getId() == medicoBuscado.getId()) {
      std::cout << c << "\n";
      encontroMedico = true;
    }
  }
  if (!encontroMedico) {
    std::cout << "No hay consultas para ese medico.\n\n";
  }

  const Paciente& pacienteBuscado = p3;
  std::cout << "=== Consultas del paciente: " << pacienteBuscado.getNombre() << " ===\n";
  bool encontroPaciente = false;
  for (const Consulta& c : consultas) {
    if (c.getPaciente()->getId() == pacienteBuscado.getId()) {
      std::cout << c << "\n";
      encontroPaciente = true;
    }
  }
  if (!encontroPaciente) {
    std::cout << "No hay consultas para ese paciente.\n";
  }

  return 0;
}