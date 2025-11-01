#pragma once
#include "frmNuevoRol.h"

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

	/// <summary>
	/// Resumen de frmMantRoles
	/// </summary>
	public ref class frmMantRoles : public System::Windows::Forms::Form
	{
	public:
		frmMantRoles(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->rolController = gcnew RolController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantRoles()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: RolController^ rolController;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ btnMostrarTodos;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnMostrarTodos = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(443, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterio de Búsqueda";
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(352, 49);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(2);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(56, 19);
			this->btnBuscar->TabIndex = 5;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(49, 49);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(128, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 52);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Id:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 129);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(443, 229);
			this->dataGridView1->TabIndex = 1;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Rol";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Permisos";
			this->Column3->Name = L"Column3";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(199, 381);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Nuevo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantRoles::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(326, 381);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// btnMostrarTodos
			// 
			this->btnMostrarTodos->Location = System::Drawing::Point(61, 383);
			this->btnMostrarTodos->Margin = System::Windows::Forms::Padding(2);
			this->btnMostrarTodos->Name = L"btnMostrarTodos";
			this->btnMostrarTodos->Size = System::Drawing::Size(87, 19);
			this->btnMostrarTodos->TabIndex = 17;
			this->btnMostrarTodos->Text = L"Mostrar Todos";
			this->btnMostrarTodos->UseVisualStyleBackColor = true;
			this->btnMostrarTodos->Click += gcnew System::EventHandler(this, &frmMantRoles::btnMostrarTodos_Click);
			// 
			// frmMantRoles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 430);
			this->Controls->Add(this->btnMostrarTodos);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantRoles";
			this->Text = L"frmMantRoles";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public:	void mostrarGrilla(List<Rol^>^ listaRoles)
		{
			this->dataGridView1->Rows->Clear();
			for (int i = 0; i < listaRoles->Count; i++)
			{
				Rol^ rol = listaRoles[i];
				array<String^>^ filaGrilla = gcnew array<String^>(7);
				filaGrilla[0] = Convert::ToString(rol->GetId());
				filaGrilla[1] = rol->GetNombre();

				List<bool>^ listaPermisos = rol->GetPermisos();
				String^ permisosStr = "";

				for (int i = 0; i < listaPermisos->Count; i++) {
					permisosStr += listaPermisos[i] ? "1" : "0";
					if (i < listaPermisos->Count - 1)
						permisosStr += "|";
				}

				this->dataGridView1->Rows->Add(filaGrilla);
			}

			this->dataGridView1->AutoGenerateColumns = false; // Desactivar la generaci�n autom�tica de columnas
			this->dataGridView1->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		}

		private: System::Void btnMostrarTodos_Click(System::Object^ sender, System::EventArgs^ e) {
			this->dataGridView1->Rows->Clear();

			List<Rol^>^ listaRoles = this->rolController->obtenerTodosRoles();
			mostrarGrilla(listaRoles);
		}
	
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			frmNuevoRol^ nuevoRolForm = gcnew frmNuevoRol(rolController);
			nuevoRolForm->ShowDialog();
		}
	};
}
