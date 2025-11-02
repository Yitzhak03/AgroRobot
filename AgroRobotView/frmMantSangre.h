#pragma once
#include "frmNuevoMuestraS.h"
#include "frmEditarMuestraS.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotModel;
	using namespace AgroRobotController;

	/// <summary>
	/// Resumen de frmMantSangre
	/// </summary>
	public ref class frmMantSangre : public System::Windows::Forms::Form
	{
	public:
		frmMantSangre(void)
		{
			InitializeComponent();
			this->muestraController = gcnew MuestraController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantSangre()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button4;
	protected:
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;







	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: MuestraController^ muestraController;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;












































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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(439, 357);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 27;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantSangre::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(292, 357);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 26;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantSangre::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(135, 357);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantSangre::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(179, 25);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(318, 100);
			this->groupBox1->TabIndex = 23;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterio de Busqueda";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(210, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantSangre::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(67, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID Animal:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			});
			this->dataGridView1->Location = System::Drawing::Point(34, 153);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(566, 180);
			this->dataGridView1->TabIndex = 28;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Muestra";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"ID Animal";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Cantidad Extraida";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Presencia de Coagulos";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Contaminacion Visible";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Color";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Fecha";
			this->Column7->Name = L"Column7";
			// 
			// frmMantSangre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(640, 405);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantSangre";
			this->Text = L"Gestion de Muestras de Sangre";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		frmNuevoMuestraS^ nuevaMuestraSangre = gcnew frmNuevoMuestraS();
		nuevaMuestraSangre->ShowDialog();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//MuestraController^ controller = gcnew MuestraController();
		List<Muestra^>^ listaFiltrada = gcnew List<Muestra^>();

		String^ textoId = this->textBox1->Text->Trim();

		if (String::IsNullOrEmpty(textoId)) {
			// Mostrar todas las muestras de sangre
			List<Muestra^>^ todas = muestraController->buscarTodasMuestrasArchivo();
			for each (Muestra ^ m in todas) {
				if (m->getTipo()->Equals("Sangre")) {
					listaFiltrada->Add(m);
				}
			}
		}
		else {
			// Buscar por ID de animal
			int idAnimal;
			if (!Int32::TryParse(textoId, idAnimal)) {
				MessageBox::Show("Ingrese un ID de animal válido.");
				return;
			}
			List<Muestra^>^ listaMuestras = muestraController->buscarMuestrasPorAnimalArchivo(idAnimal);
			for each (Muestra ^ m in listaMuestras) {
				if (m->getTipo()->Equals("Sangre")) {
					listaFiltrada->Add(m);
				}
			}
		}

		this->dataGridView1->Rows->Clear();
		if (listaFiltrada->Count == 0) {
			MessageBox::Show("No se encontraron muestras de sangre.");
		}
		else {
			mostrarGrilla(listaFiltrada);
		}
	}

	private: void mostrarGrilla(List<Muestra^> ^ listaMuestras) {
		for (int i = 0; i < listaMuestras->Count; i++) {
			Muestra^ m = listaMuestras[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(m->getIdMuestra());
			filaGrilla[1] = Convert::ToString(m->getIdAnimal());
			filaGrilla[2] = m->getCantidadExtraida();
			filaGrilla[3] = m->getCoagulos();
			filaGrilla[4] = m->getContaminacion();
			filaGrilla[5] = m->getColorSangre();
			filaGrilla[6] = m->getFechaToma();
			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}
	
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idMuestraEditar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		Muestra^ muestra = this->muestraController->buscarMuestraPorIdArchivo(idMuestraEditar);
		if (muestra == nullptr || muestra->getTipo() != "Sangre") {
			MessageBox::Show("La muestra seleccionada no es válida o no es de tipo sangre.");
			return;
		}

		frmEditarMuestraS^ ventanaEditar = gcnew frmEditarMuestraS(muestra, this->muestraController);
		ventanaEditar->ShowDialog();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione una muestra para eliminar.");
			return;
		}

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idEliminar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		this->muestraController->eliminarMuestraArchivo(idEliminar);
		MessageBox::Show("La muestra ha sido eliminada con éxito.");
	}
};
}
