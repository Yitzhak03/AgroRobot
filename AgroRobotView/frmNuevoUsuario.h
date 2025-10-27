#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic; //Añadido
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	// Referencia al Controlador y Modelo
	using namespace AgroRobotController;
	using namespace AgroRobotModel;
	/// <summary>
	/// Resumen de frmNuevoUsuario
	/// </summary>
	public ref class frmNuevoUsuario : public System::Windows::Forms::Form {
	public:
		frmNuevoUsuario(void)
		{
			InitializeComponent();
			// Obtener los roles desde el controlador
			RolController^ rolCtrl = gcnew RolController();
			List<Rol^>^ listaRoles = rolCtrl->readTxt();
			// Limpiar los items existentes
			checkedListBox1->Items->Clear();
			// Agregar los nombres de los roles al CheckedListBox
			for each (Rol ^ rol in listaRoles) {
				checkedListBox1->Items->Add(rol->Nombre);
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoUsuario()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;


	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(148, 348);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(66, 19);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmNuevoUsuario::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(77, 348);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 19);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Grabar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmNuevoUsuario::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkedListBox1);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 11);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(280, 320);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del Usuario";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->CheckOnClick = true;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(137, 225);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(101, 79);
			this->checkedListBox1->TabIndex = 16;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmNuevoUsuario::checkedListBox1_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(41, 225);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Roles:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(137, 179);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(101, 20);
			this->textBox4->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(137, 129);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(101, 20);
			this->textBox3->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(137, 85);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(101, 20);
			this->textBox2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(137, 41);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(101, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 181);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Contraseña:  ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(41, 132);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Correo:  ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 88);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nombre: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 44);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id: ";
			// 
			// frmNuevoUsuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(303, 388);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmNuevoUsuario";
			this->Text = L"frmNuevoUsuario";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//===============================================================================
		//==============================Grabar===========================================
		//===============================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Crear el objeto Usuario
		Usuario^ nuevoUsuario = gcnew Usuario();
		nuevoUsuario->Id = Convert::ToInt32(textBox1->Text);
		nuevoUsuario->Nombre = textBox2->Text;
		nuevoUsuario->Email = textBox3->Text;
		nuevoUsuario->Contrasenha = textBox4->Text;
		nuevoUsuario->UltimoAcceso = ""; // Inicialmente vacío
		nuevoUsuario->EstadoCuenta = "Nuevo"; // Estado por defecto
		nuevoUsuario->IdsAlertas = nullptr; // Inicialmente sin alertas
		// Creación de la lista de IdsRoles
		nuevoUsuario->IdsRoles = gcnew List<int>();
		//Crear el controlador de roles
		RolController^ rolCtrl = gcnew RolController();
		// Agregar los roles seleccionados
		for (int i = 0; i < checkedListBox1->Items->Count; i++) {
			if (checkedListBox1->GetItemChecked(i)) {
				String^ rolNombre = checkedListBox1->Items[i]->ToString();
				// Obtener el Id del rol
				int rolId = rolCtrl->obtenerIdPorNombre(rolNombre);
				// Agregar el Id del rol a la lista de IdsRoles del usuario
				nuevoUsuario->IdsRoles->Add(rolId);
			}
		}
		// Llamar al controlador para agregar el nuevo usuario
		UsuarioController^ userCtrl = gcnew UsuarioController();
		userCtrl->agregarUsuario(nuevoUsuario);
		// Confirmación
		MessageBox::Show("Usuario agregado correctamente.", "Nuevo Usuario", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
		   //===============================================================================
		   //==============================Cancelar=========================================
		   //===============================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
