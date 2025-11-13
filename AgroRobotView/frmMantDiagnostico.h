#pragma once
#include "frmNuevoDiagnostico.h"
#include "frmEditarDiagnostico.h"

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
	/// Resumen de frmMantDiagnostico
	/// </summary>
	public ref class frmMantDiagnostico : public System::Windows::Forms::Form
	{
	public:
		frmMantDiagnostico(void)
		{
			InitializeComponent();
			this->diagnosticoController = gcnew DiagnosticoController();
			this->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->BackColor = System::Drawing::Color::LightGreen;
			this->button1->ForeColor = System::Drawing::Color::DarkGreen;
			this->button2->BackColor = System::Drawing::Color::LightGreen;
			this->button2->ForeColor = System::Drawing::Color::DarkGreen;
			this->button3->BackColor = System::Drawing::Color::LightGreen;
			this->button3->ForeColor = System::Drawing::Color::DarkGreen;
			this->button4->BackColor = System::Drawing::Color::LightGreen;
			this->button4->ForeColor = System::Drawing::Color::DarkGreen;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantDiagnostico()
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
	private: System::Windows::Forms::DataGridView^ dataGridView1;






	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: DiagnosticoController^ diagnosticoController;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;











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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(607, 446);
			this->button4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 28);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(357, 446);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(128, 446);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column7,
					this->Column1, this->Column2, this->Column3, this->Column4, this->Column5, this->Column8, this->Column6
			});
			this->dataGridView1->Location = System::Drawing::Point(32, 186);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(793, 225);
			this->dataGridView1->TabIndex = 9;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"ID Diagnostico";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->Width = 125;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Animal";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
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
			this->Column3->HeaderText = L"Resultado de heces";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Resultado de hemograma";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Estado de salud";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Observaciones";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			this->Column8->Width = 125;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Fecha";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(147, 36);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(599, 123);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterio de Busqueda";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(491, 43);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(319, 43);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(247, 47);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Especie:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(89, 43);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 47);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID Animal:";
			// 
			// frmMantDiagnostico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(881, 597);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"frmMantDiagnostico";
			this->Text = L"AgroRobot - Gestion de Diagnosticos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		frmNuevoDiagnostico^ nuevoDiagnostico = gcnew frmNuevoDiagnostico();
		nuevoDiagnostico->ShowDialog();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Diagnostico^>^ listaFiltrada = gcnew List<Diagnostico^>();
		String^ textoId = this->textBox1->Text->Trim();

		if (String::IsNullOrEmpty(textoId)) {
			// Mostrar todos los diagnósticos
			List<Diagnostico^>^ todos = diagnosticoController->buscarTodosDiagnosticosArchivo();
			listaFiltrada->AddRange(todos);
		}
		else {
			// Buscar por ID de animal
			int idAnimal;
			if (!Int32::TryParse(textoId, idAnimal)) {
				MessageBox::Show("Ingrese un ID de animal válido.");
				return;
			}
			List<Diagnostico^>^ listaPorAnimal = diagnosticoController->buscarDiagnosticosPorAnimalArchivo(idAnimal);
			listaFiltrada->AddRange(listaPorAnimal);
		}

		this->dataGridView1->Rows->Clear();
		if (listaFiltrada->Count == 0) {
			MessageBox::Show("No se encontraron diagnósticos.");
		}
		else {
			mostrarGrillaDiagnostico(listaFiltrada);
		}
	}

	private: void mostrarGrillaDiagnostico(List<Diagnostico^>^ listaDiagnosticos) {
		for each (Diagnostico ^ d in listaDiagnosticos) {
			array<String^>^ fila = gcnew array<String^>(8);
			fila[0] = Convert::ToString(d->getIdDiagnostico());
			fila[1] = Convert::ToString(d->getIdAnimal());
			fila[2] = d->getEspecie();
			fila[3] = d->getResultadoHeces();
			fila[4] = d->getResultadoSangre();
			fila[5] = d->getEstadoSalud();
			fila[6] = d->getObservaciones();
			fila[7] = d->getFecha();
			this->dataGridView1->Rows->Add(fila);
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione un diagnóstico para eliminar.");
			return;
		}

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idEliminar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		this->diagnosticoController->eliminarDiagnosticoArchivo(idEliminar);
		MessageBox::Show("El diagnóstico ha sido eliminado con éxito.");

		// Opcional: recargar la grilla
		List<Diagnostico^>^ listaActualizada = diagnosticoController->buscarTodosDiagnosticosArchivo();
		this->dataGridView1->Rows->Clear();
		mostrarGrillaDiagnostico(listaActualizada);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione un diagnóstico para editar.");
			return;
		}

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int codigoEditar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		Diagnostico^ diagnostico = this->diagnosticoController->buscarDiagnosticoPorIdArchivo(codigoEditar);
		frmEditarDiagnostico^ ventanaEditar = gcnew frmEditarDiagnostico(diagnostico, this->diagnosticoController);
		ventanaEditar->ShowDialog();
	}
};
}
