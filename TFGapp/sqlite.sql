.cd C:/Users/Ulises/Desktop/tfg/TFGapp/TFGapp .open test.db

CREATE TABLE IF NOT EXISTS alumnos(
	nombre TEXT,
	apellido1 TEXT,
	apellido2 TEXT,
	ID TEXT PRIMARY KEY NOT NULL,
	grado TEXT,
	FOREIGN KEY(grado) REFERENCES grados(nombre)
	ON UPDATE CASCADE ON DELETE NULL
);

CREATE TABLE IF NOT EXISTS profesores(
	nombreCompleto TEXT  PRIMARY KEY NOT NULL,
	doctor INT
);

CREATE TABLE IF NOT EXISTS grados(
	nombre TEXT PRIMARY KEY NOT NULL
);

--Tabla que conecta profesores y grados 
CREATE TABLE IF NOT EXISTS especialidades(
	nombreProfesor TEXT,
	nombreGrado TEXT,
	numeroMax INT,
	FOREIGN KEY(nombreProfesor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(nombreGrado) REFERENCES grados(nombre)
	ON UPDATE CASCADE ON DELETE CASCADE,
	PRIMARY KEY (nombreProfesor, nombreGrado)
);

CREATE TABLE IF NOT EXISTS disponibilidad(
	nombreProfesor TEXT NOT NULL,
	dia INT,
	sloot1 INT,
	sloot2 INT,
	sloot3 INT,
	sloot4 INT,
	sloot5 INT,
	sloot6 INT,
	sloot7 INT,
	PRIMARY KEY(nombreProfesor, dia),
	FOREIGN KEY(nombreProfesor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS tfg(
	titulo TEXT PRIMARY KEY,
	presentado INT,
	tutor TEXT,
	cotutor TEXT,
	FOREIGN KEY(tutor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(cotutor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(alumno) REFERENCES alumnos(ID)
	ON UPDATE CASCADE ON DELETE CASCADE,
);

CREATE TABLE IF NOT EXISTS presentacion(
	tfg TEXT,
	idPresentacion TEXT PRIMARY KEY,
	hora INT,
	dia INT,
	aula INT,
	slot INT,
	convocatoria INT,
	FOREIGN KEY(tfg) REFERENCES tfg(titulo)
	ON UPDATE CASCADE ON DELETE CASCADE,
);

CREATE TABLE IF NOT EXISTS tribunales(
	presentacion TEXT,
	profesor TEXT,
	FOREIGN KEY(presentacion) REFERENCES presentacion(idPresentacion)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(profesor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	PRIMARY KEY(presentacion, profesor)
);