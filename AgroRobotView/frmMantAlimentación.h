#pragma once
#include "frmProgreso.h"

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

	/// <summary>
	/// Resumen de frmMantAlimentación
	/// </summary>
	public ref class frmMantAlimentación : public System::Windows::Forms::Form
	{
	public:
		frmMantAlimentación(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->animalController = gcnew GestorNutricionalController();
			aplicarEstilo();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
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
	private: GestorNutricionalController^ animalController;
	private: frmProgreso^ ventanaProgreso;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;

		   void aplicarEstilo()
		   {
			   this->BackColor = System::Drawing::Color::FromArgb(30, 61, 54);

			   this->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10, FontStyle::Regular);
			   this->ForeColor = System::Drawing::Color::FromArgb(242, 242, 242);

			   this->groupBox1->BackColor = System::Drawing::Color::FromArgb(45, 93, 80);
			   this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(242, 242, 242);
			   this->groupBox1->Font = gcnew System::Drawing::Font(L"Bahnschrift", 11, FontStyle::Bold);
			   this->groupBox1->Text = L"Criterios de búsqueda";

			   array<TextBox^>^ textos = { this->textBox2};
			   for each (TextBox ^ t in textos) {
				   t->BackColor = System::Drawing::Color::FromArgb(60, 110, 95);
				   t->ForeColor = System::Drawing::Color::White;
				   t->BorderStyle = BorderStyle::FixedSingle;
				   t->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10);
			   }

			   this->button1->BackColor = System::Drawing::Color::FromArgb(123, 228, 149);
			   this->button1->FlatStyle = FlatStyle::Flat;
			   this->button1->FlatAppearance->BorderSize = 0;
			   this->button1->ForeColor = System::Drawing::Color::Black;
			   this->button1->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);


			   this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(45, 93, 80);
			   this->dataGridView1->BorderStyle = BorderStyle::None;
			   this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(30, 61, 54);
			   this->dataGridView1->EnableHeadersVisualStyles = false;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(30, 61, 54);
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			   this->dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(60, 110, 95);
			   this->dataGridView1->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			   this->dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(123, 228, 149);
			   this->dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;

			   this->groupBox1->BackColor = System::Drawing::Color::FromArgb(45, 93, 80);
			   this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(242, 242, 242);
			   this->groupBox1->Font = gcnew System::Drawing::Font(L"Bahnschrift", 11, FontStyle::Bold);

			   this->groupBox2->BackColor = System::Drawing::Color::FromArgb(45, 93, 80);
			   this->groupBox2->ForeColor = System::Drawing::Color::FromArgb(242, 242, 242);
			   this->groupBox2->Font = gcnew System::Drawing::Font(L"Bahnschrift", 11, FontStyle::Bold);

			   array<Button^>^ botones = { this->button2, this->button3, this->button1};
			   for each (Button ^ b in botones) {
				   b->BackColor = System::Drawing::Color::FromArgb(123, 228, 149);
				   b->FlatStyle = FlatStyle::Flat;
				   b->FlatAppearance->BorderSize = 0;
				   b->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);
				   b->ForeColor = System::Drawing::Color::Black;
				   b->Cursor = Cursors::Hand;
			   }

			   // 🏷️ Etiquetas
			   array<Label^>^ labels = { this->label2 };
			   for each (Label ^ l in labels) {
				   l->ForeColor = System::Drawing::Color::White;
				   l->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10);
			   }

			   // 📏 Config general
			   this->Text = L"AgroRobot - Gestión de alimentación";
			   this->StartPosition = FormStartPosition::CenterScreen;
		   }
	protected:







	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
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
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
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
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Visible = false;
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Especie";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Peso";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 75;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Edad";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 75;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Estado de salud:";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Ultima dieta:";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 125;
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
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(679, 99);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(532, 44);
			this->button1->Margin = System::Windows::Forms::Padding(2);
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
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(93, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(282, 50);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Especie: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 53);
			this->button2->Margin = System::Windows::Forms::Padding(2);
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
			this->groupBox2->Size = System::Drawing::Size(156, 229);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Alimentar";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(33, 152);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 24);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Por animal";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantAlimentación::button3_Click);
			// 
			// frmMantAlimentación
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(881, 385);
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
			this->ResumeLayout(false);

		}
#pragma endregion
	/*FUNCIONES AUXILIARES PARA LA COMUNICACIÓN CON EL ROBOT*/
		private: void OnSerialDataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
		{
			try {
				String^ linea = serialPort1->ReadLine()->Trim();

				if (linea->EndsWith("_COMPLETADO")) {
					/*separa la cadena de texto en 3 bloques para extraer el número de animal*/
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

		  if (ventanaProgreso != nullptr) {
			ventanaProgreso->actualizarProgreso(num);
		  }
		}

		private: void FinalizarProgresoSeguro() {
			if (this->InvokeRequired) {
				this->Invoke(gcnew System::Action(this, &frmMantAlimentación::FinalizarProgresoSeguro));
				return;
			}

			if (ventanaProgreso != nullptr) {
				ventanaProgreso->finalizar();
			}

			MessageBox::Show("El robot terminó la secuencia de alimentación.");
		}


	/*-----------------------------------------------------------------------------------------------------------*/
	public:	void mostrarGrilla(List<Animal^>^ listaAnimales){
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
		if (!textBox2->Text->Equals(""))
		{
			especie = textBox2->Text;
		}

		List<Animal^>^ listaAnimales = this->animalController->consultarAnimalporIdEspecie(id, especie);
		// Mostrar los resultados en el DataGridView
		mostrarGrilla(listaAnimales);
	}
	
	private: System::Void frmMantAlimentación_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Animal^>^ listaAnimales = this->animalController->obtenerTodosAnimales();
		mostrarGrilla(listaAnimales);

		/*código para funcionalidad del periférico*/
		try {
			serialPort1 = gcnew System::IO::Ports::SerialPort();

			serialPort1->PortName = "COM5";/*CAMBIAR POR EL CORRECTO*/
			serialPort1->BaudRate = 9600;
			serialPort1->Parity = System::IO::Ports::Parity::None;
			serialPort1->DataBits = 8;
			serialPort1->StopBits = System::IO::Ports::StopBits::One;

			serialPort1->DataReceived +=
				gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &frmMantAlimentación::OnSerialDataReceived);

			if (!serialPort1->IsOpen) {
				serialPort1->Open();
				MessageBox::Show("Conectado a AgroRobot correctamente.",
					"Conexión exitosa", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		catch (Exception^ ex){
			MessageBox::Show("Error al abrir el puerto serial: " + ex->Message,
				"Error de conexión", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	
	/*alimentar por especie*/
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);

			Animal^ animalSeleccionado = this->animalController->consultarAnimalporId(id);
			if (animalSeleccionado == nullptr)
			{
				MessageBox::Show("No se encontró el animal seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			int idEspecie = 0;
			String^ especie = animalSeleccionado->Especie;
			List<Animal^>^ listaAnimales = this->animalController->consultarAnimalporIdEspecie(idEspecie, especie);
			int cantidad = listaAnimales->Count;
			


			if (!serialPort1->IsOpen)
			{
				MessageBox::Show("El puerto serial no está abierto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			/*SECUENCIA DEL ROBOT*/
			try {
				// Abrir ventana de progreso
				this->ventanaProgreso = gcnew frmProgreso(cantidad);
				ventanaProgreso->Show();

				String^ comando = "ESPECIE," + cantidad.ToString();
				serialPort1->WriteLine(comando);

				for each (Animal ^ animal in listaAnimales){
					int idModificar = animal->IdAnimal;
					String^ fechaAlimentacion = DateTime::Now.ToString("dd/MM/yyyy HH:mm");
					this->animalController->modificarUltimaAlimentacion(idModificar, fechaAlimentacion);
				}
				/*FIN DE LA SECUENCIA*/
			}

			/*reemplazar errores por mensajes*/
			catch (Exception^ ex) {
				MessageBox::Show("Error al comunicar con el periférico: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un animal para iniciar la secuencia.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}


	/*alimentar individualmente*/
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);

			Animal^ animalSeleccionado = this->animalController->consultarAnimalporId(id);
			if (animalSeleccionado == nullptr)
			{
				MessageBox::Show("No se encontró el animal seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			

			/*SECUENCIA DEL ROBOT*/
			if (!serialPort1->IsOpen)
			{
				MessageBox::Show("El puerto serial no está abierto.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			
			// Abrir ventana de progreso
			this->ventanaProgreso = gcnew frmProgreso(1);
			ventanaProgreso->Show();

			// Enviar comando al Arduino
			serialPort1->WriteLine("ANIMAL");

			//actualiza la fecha de ultima alimentación
			String^ fechaAlimentacion = DateTime::Now.ToString("dd/MM/yyyy HH:mm");
			this->animalController->modificarUltimaAlimentacion(id, fechaAlimentacion);

			/*FIN DE LA SECUENCIA*/

		}
		else
		{
			MessageBox::Show("Por favor, seleccione un animal para iniciar la secuencia.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	private: System::Void frmMantAlimentación_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		try {
			if (serialPort1 != nullptr && serialPort1->IsOpen) {
				serialPort1->Close();
				MessageBox::Show("Conexión con AgroRobot terminada.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cerrar el puerto serial: " + ex->Message);
		}
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
