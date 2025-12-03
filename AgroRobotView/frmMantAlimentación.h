#pragma once
#include "frmProgreso.h"
#include "frmRendimiento.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;
	using namespace System::IO::Ports;

	public ref class frmMantAlimentación : public System::Windows::Forms::Form
	{
	public:
		frmMantAlimentación(void)
		{
			InitializeComponent();
			this->animalController = gcnew GestorNutricionalController();
			this->rendimientoController = gcnew RendimientoController();

			// Aplicar el diseño Menta/Bosque
			AplicarEstiloProfesional();
		}

	protected:
		~frmMantAlimentación()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ btonMotores;
	private: GestorNutricionalController^ animalController;
	private: frmProgreso^ ventanaProgreso;
	private: RendimientoController^ rendimientoController;


	private: System::ComponentModel::Container^ components;

		   // ===================================================================================
		   // MÉTODO DE ESTILO PROFESIONAL (MENTA/BOSQUE)
		   // ===================================================================================
		   void AplicarEstiloProfesional() {
			   // 1. PALETA DE COLORES
			   System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248);   // Menta Pálido
			   System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240);   // Menta Crema
			   System::Drawing::Color colorBtnPrimario = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Bosque
			   System::Drawing::Color colorTextoMain = System::Drawing::Color::FromArgb(22, 53, 45);    // Verde Petróleo
			   System::Drawing::Color colorTextoSec = System::Drawing::Color::FromArgb(64, 106, 90);    // Verde Azulado
			   System::Drawing::Color colorGridLine = System::Drawing::Color::FromArgb(183, 220, 200);   // Verde Agua

			   // 2. FUENTES
			   System::Drawing::Font^ fontTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 10, FontStyle::Bold);
			   System::Drawing::Font^ fontCuerpo = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Regular);
			   System::Drawing::Font^ fontGridHeader = gcnew System::Drawing::Font("Segoe UI Semibold", 10);
			   System::Drawing::Font^ fontGridCell = gcnew System::Drawing::Font("Microsoft Sans Serif", 9);

			   // 3. CONFIGURACIÓN VENTANA
			   this->BackColor = colorFondo;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; // Estilo incrustado MDI
			   this->Dock = DockStyle::Fill;
			   this->Text = L"AgroRobot - Gestión de Alimentación";

			   // 4. GROUPBOX BÚSQUEDA (Superior)
			   EstilarGroupBox(this->groupBox1, colorPanel, colorTextoSec, fontTitulo);
			   // Posicionamiento
			   int margen = 20;
			   this->groupBox1->Location = System::Drawing::Point(margen, 20);
			   this->groupBox1->Width = this->ClientSize.Width - (margen * 2); // Estirar
			   this->groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);

			   // Controles de Búsqueda
			   this->label2->ForeColor = colorTextoMain;
			   this->label2->Font = fontCuerpo;

			   this->textBox2->BackColor = System::Drawing::Color::White;
			   this->textBox2->ForeColor = colorTextoMain;
			   this->textBox2->BorderStyle = BorderStyle::FixedSingle;
			   this->textBox2->Font = fontCuerpo;

			   EstilarBoton(this->button1, colorBtnPrimario, fontTitulo); // Botón Buscar

			   // 5. GROUPBOX ALIMENTAR (Lateral Derecho)
			   EstilarGroupBox(this->groupBox2, colorPanel, colorTextoSec, fontTitulo);
			   // Posicionamiento - Fijo a la derecha
			   int anchoPanelAccion = 180;
			   this->groupBox2->Size = System::Drawing::Size(anchoPanelAccion, 200);
			   this->groupBox2->Location = System::Drawing::Point(this->ClientSize.Width - anchoPanelAccion - margen, this->groupBox1->Bottom + 20);
			   this->groupBox2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right);

			   // Botones de Alimentación
			   EstilarBoton(this->button2, colorBtnPrimario, fontTitulo);
			   EstilarBoton(this->button3, colorBtnPrimario, fontTitulo);

			   // Ajuste manual de botones dentro del GroupBox derecho
			   this->button2->Left = (this->groupBox2->Width - this->button2->Width) / 2; // Centrar btn
			   this->button3->Left = (this->groupBox2->Width - this->button3->Width) / 2; // Centrar btn
			   this->button2->Top = 50;
			   this->button3->Top = 100;

			   // 6. GRILLA (Central)
			   this->dataGridView1->Location = System::Drawing::Point(margen, this->groupBox1->Bottom + 20);
			   // Ancho = Total - MargenIzq - AnchoPanelDerecho - MargenIntermedio - MargenDer
			   this->dataGridView1->Width = this->ClientSize.Width - margen - anchoPanelAccion - 40;
			   this->dataGridView1->Height = this->ClientSize.Height - this->dataGridView1->Top - margen;
			   this->dataGridView1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			   // Estilo Visual Grilla
			   this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			   this->dataGridView1->BorderStyle = BorderStyle::None;
			   this->dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
			   this->dataGridView1->GridColor = colorGridLine;
			   this->dataGridView1->EnableHeadersVisualStyles = false;

			   this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorPanel;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = colorTextoMain;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = fontGridHeader;
			   this->dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::White;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->SelectionForeColor = colorTextoMain;

			   this->dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::White;
			   this->dataGridView1->DefaultCellStyle->ForeColor = colorTextoMain;
			   this->dataGridView1->DefaultCellStyle->Font = fontGridCell;
			   this->dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightGreen;
			   this->dataGridView1->DefaultCellStyle->SelectionForeColor = colorTextoMain;
			   this->dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(244, 250, 246);

			   this->dataGridView1->RowHeadersVisible = false;
			   this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			   this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		   }

		   // Helpers
		   void EstilarBoton(Button^ btn, Color back, System::Drawing::Font^ font) {
			   btn->BackColor = back;
			   btn->ForeColor = System::Drawing::Color::White;
			   btn->FlatStyle = FlatStyle::Flat;
			   btn->FlatAppearance->BorderSize = 0;
			   btn->Font = font;
			   btn->Cursor = Cursors::Hand;
		   }

		   void EstilarGroupBox(GroupBox^ gb, Color back, Color text, System::Drawing::Font^ font) {
			   gb->BackColor = back;
			   gb->ForeColor = text;
			   gb->Font = font;
		   }

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			   this->btonMotores = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->groupBox3->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				   this->Column1,
					   this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			   });
			   this->dataGridView1->Location = System::Drawing::Point(17, 132);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->Size = System::Drawing::Size(679, 229);
			   this->dataGridView1->TabIndex = 13;
			   this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMantAlimentación::dataGridView1_CellContentClick);
			   // 
			   // Column1
			   // 
			   this->Column1->HeaderText = L"ID Animal";
			   this->Column1->Name = L"Column1";
			   this->Column1->Visible = false;
			   // 
			   // Column2
			   // 
			   this->Column2->HeaderText = L"Especie";
			   this->Column2->Name = L"Column2";
			   // 
			   // Column3
			   // 
			   this->Column3->HeaderText = L"Peso";
			   this->Column3->Name = L"Column3";
			   // 
			   // Column4
			   // 
			   this->Column4->HeaderText = L"Edad";
			   this->Column4->Name = L"Column4";
			   // 
			   // Column5
			   // 
			   this->Column5->HeaderText = L"Estado de salud";
			   this->Column5->Name = L"Column5";
			   // 
			   // Column6
			   // 
			   this->Column6->HeaderText = L"Ultima dieta";
			   this->Column6->Name = L"Column6";
			   // 
			   // Column7
			   // 
			   this->Column7->HeaderText = L"Ultima Vez Alimentado";
			   this->Column7->Name = L"Column7";
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->button1);
			   this->groupBox1->Controls->Add(this->textBox2);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Location = System::Drawing::Point(17, 19);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(679, 99);
			   this->groupBox1->TabIndex = 14;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Criterios de Búsqueda";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(532, 44);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(75, 24);
			   this->button1->TabIndex = 4;
			   this->button1->Text = L"Buscar";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &frmMantAlimentación::button1_Click);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(366, 47);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(93, 20);
			   this->textBox2->TabIndex = 3;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(282, 50);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(51, 13);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Especie: ";
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(33, 36);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(90, 24);
			   this->button2->TabIndex = 5;
			   this->button2->Text = L"Por especie";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &frmMantAlimentación::button2_Click);
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->button3);
			   this->groupBox2->Controls->Add(this->button2);
			   this->groupBox2->Location = System::Drawing::Point(713, 132);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Size = System::Drawing::Size(156, 133);
			   this->groupBox2->TabIndex = 5;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Alimentar";
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(33, 84);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(90, 24);
			   this->button3->TabIndex = 6;
			   this->button3->Text = L"Por animal";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &frmMantAlimentación::button3_Click);
			   // 
			   // groupBox3
			   // 
			   this->groupBox3->Controls->Add(this->btonMotores);
			   this->groupBox3->Location = System::Drawing::Point(713, 283);
			   this->groupBox3->Name = L"groupBox3";
			   this->groupBox3->Size = System::Drawing::Size(156, 79);
			   this->groupBox3->TabIndex = 7;
			   this->groupBox3->TabStop = false;
			   this->groupBox3->Text = L"Revisión de Robot";
			   // 
			   // btonMotores
			   // 
			   this->btonMotores->Location = System::Drawing::Point(33, 33);
			   this->btonMotores->Name = L"btonMotores";
			   this->btonMotores->Size = System::Drawing::Size(90, 24);
			   this->btonMotores->TabIndex = 5;
			   this->btonMotores->Text = L"Ver Motores";
			   this->btonMotores->UseVisualStyleBackColor = true;
			   this->btonMotores->Click += gcnew System::EventHandler(this, &frmMantAlimentación::btonMotores_Click);
			   // 
			   // frmMantAlimentación
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(881, 385);
			   this->Controls->Add(this->groupBox3);
			   this->Controls->Add(this->groupBox2);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->dataGridView1);
			   this->Name = L"frmMantAlimentación";
			   this->Text = L"Gestión de Alimentación";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMantAlimentación::frmMantAlimentación_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &frmMantAlimentación::frmMantAlimentación_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox3->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   // LÓGICA DE NEGOCIO (PRESERVADA)
	private: void OnSerialDataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
	{
		try {
			String^ linea = serialPort1->ReadLine()->Trim();
			if (linea->EndsWith("_COMPLETADO")) {
				array<String^>^ partes = linea->Split('_');
				int numero = Convert::ToInt32(partes[1]);
				this->ActualizarProgresoSeguro(numero);
			}
			else if (linea == "FIN_ANIMAL" || linea == "FIN_ESPECIE") {
				this->FinalizarProgresoSeguro();
			}
		}
		catch (...) {}
	}

	private: void ActualizarProgresoSeguro(int num) {
		if (this->InvokeRequired) {
			this->Invoke(gcnew System::Action<int>(this, &frmMantAlimentación::ActualizarProgresoSeguro), num);
			return;
		}
		if (ventanaProgreso != nullptr) ventanaProgreso->actualizarProgreso(num);
	}

	private: void FinalizarProgresoSeguro() {
		if (this->InvokeRequired) {
			this->Invoke(gcnew System::Action(this, &frmMantAlimentación::FinalizarProgresoSeguro));
			return;
		}
		if (ventanaProgreso != nullptr) ventanaProgreso->finalizar();
		MessageBox::Show("El robot terminó la secuencia de alimentación.");
	}

	public:	void mostrarGrilla(List<Animal^>^ listaAnimales) {
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < listaAnimales->Count; i++)
		{
			Animal^ animal = listaAnimales[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(animal->IdAnimal);
			filaGrilla[1] = animal->Especie;
			filaGrilla[2] = Convert::ToString(animal->Peso);
			filaGrilla[3] = Convert::ToString(animal->Edad);
			filaGrilla[4] = animal->EstadoSalud;
			filaGrilla[5] = animal->UltimaDieta;
			filaGrilla[6] = animal->UltimaVezAlimentado;
			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = 0;
		String^ especie = "";
		if (!textBox2->Text->Equals("")) especie = textBox2->Text;
		List<Animal^>^ listaAnimales = this->animalController->consultarAnimalporIdEspecie(id, especie);
		mostrarGrilla(listaAnimales);
	}

	private: System::Void frmMantAlimentación_Load(System::Object^ sender, System::EventArgs^ e) {
		//SOLO SI NO HAY UNA INSTANCIA DE RENDIMIENTO SE VA A CREAR, PUES SOLO SE NECESITA 1
		if (this->rendimientoController->buscarTodos()->Count < 1) {
			Rendimiento^ rendimiento = gcnew Rendimiento(1, 0, 0, 0);
			this->rendimientoController->agregarRendimiento(rendimiento);
		}
		
		List<Animal^>^ listaAnimales = this->animalController->obtenerTodosAnimales();
		mostrarGrilla(listaAnimales);

		try {
			serialPort1 = gcnew System::IO::Ports::SerialPort();
			serialPort1->PortName = "COM5";
			serialPort1->BaudRate = 9600;
			serialPort1->Parity = System::IO::Ports::Parity::None;
			serialPort1->DataBits = 8;
			serialPort1->StopBits = System::IO::Ports::StopBits::One;
			serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &frmMantAlimentación::OnSerialDataReceived);

			if (!serialPort1->IsOpen) {
				serialPort1->Open();
				MessageBox::Show("Conectado a AgroRobot correctamente.", "Conexión", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al abrir puerto serial: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//ALIMENTAR 1 ESPECIE ENTERA
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0) {
			int fila = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[fila]->Cells[0]->Value);
			Animal^ animal = this->animalController->consultarAnimalporId(id);

			if (animal == nullptr) return;

			int cantidad = this->animalController->consultarAnimalporIdEspecie(0, animal->Especie)->Count;
			this->rendimientoController->actualizarxAnimal(cantidad);//se actualiza el rendimiento

			if (!serialPort1->IsOpen) {
				MessageBox::Show("Puerto cerrado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			try {
				this->ventanaProgreso = gcnew frmProgreso(cantidad);
				ventanaProgreso->Show();
				serialPort1->WriteLine("ESPECIE," + cantidad.ToString());
			}
			catch (...) {}
		}
		else {
			MessageBox::Show("Seleccione un animal.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	//ALIMENTAR 1 ANIMAL
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0) {
			int id = Convert::ToInt32(this->dataGridView1->Rows[this->dataGridView1->SelectedRows[0]->Index]->Cells[0]->Value);

			if (!serialPort1->IsOpen) {
				MessageBox::Show("Puerto cerrado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			this->ventanaProgreso = gcnew frmProgreso(1);
			ventanaProgreso->Show();
			serialPort1->WriteLine("ANIMAL");

			String^ fecha = DateTime::Now.ToString("dd/MM/yyyy HH:mm");
			this->animalController->modificarUltimaAlimentacion(id, fecha);
			this->rendimientoController->actualizarxAnimal(1);
		}
		else {
			MessageBox::Show("Seleccione un animal.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	private: System::Void frmMantAlimentación_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		try {
			if (serialPort1 != nullptr && serialPort1->IsOpen) {
				serialPort1->Close();
				MessageBox::Show("Conexión terminada.");
			}
		}
		catch (...) {}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
	
	private: System::Void btonMotores_Click(System::Object^ sender, System::EventArgs^ e) {
		frmRendimiento^ ventanaRendimiento = gcnew frmRendimiento();
	}
};
}