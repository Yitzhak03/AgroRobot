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
		frmNuevoUsuario(UsuarioController^ usuarioController) {
			InitializeComponent();
			this->usuarioController = usuarioController;
			this->rolController = gcnew RolController();

			// Obtener los roles desde el controlador
			this->comboBox1->Items->Clear();
			List<Rol^>^ listaRoles = this->rolController->obtenerTodosRoles();
			for each (Rol ^ rol in listaRoles) {
				this->comboBox1->Items->Add(rol->GetNombre());
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
	private: System::Windows::Forms::TextBox^ txtCtrsn;



	private: System::Windows::Forms::TextBox^ txtCorreo;

	private: System::Windows::Forms::TextBox^ txtNombre;

	private: System::Windows::Forms::TextBox^ txtId;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Label^ label7;

	private: RolController^ rolController;
	private: UsuarioController^ usuarioController;
	private: System::Windows::Forms::ComboBox^ comboBox1;



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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtCtrsn = (gcnew System::Windows::Forms::TextBox());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(174, 348);
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
			this->button1->Location = System::Drawing::Point(100, 348);
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
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->txtCtrsn);
			this->groupBox1->Controls->Add(this->txtCorreo);
			this->groupBox1->Controls->Add(this->txtNombre);
			this->groupBox1->Controls->Add(this->txtId);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 11);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(305, 320);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del Usuario";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmNuevoUsuario::groupBox1_Enter);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(137, 223);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(127, 21);
			this->comboBox1->TabIndex = 13;
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
			// txtCtrsn
			// 
			this->txtCtrsn->Location = System::Drawing::Point(137, 179);
			this->txtCtrsn->Margin = System::Windows::Forms::Padding(2);
			this->txtCtrsn->Name = L"txtCtrsn";
			this->txtCtrsn->Size = System::Drawing::Size(127, 20);
			this->txtCtrsn->TabIndex = 9;
			// 
			// txtCorreo
			// 
			this->txtCorreo->Location = System::Drawing::Point(137, 129);
			this->txtCorreo->Margin = System::Windows::Forms::Padding(2);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(127, 20);
			this->txtCorreo->TabIndex = 8;
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(137, 85);
			this->txtNombre->Margin = System::Windows::Forms::Padding(2);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(127, 20);
			this->txtNombre->TabIndex = 7;
			// 
			// txtId
			// 
			this->txtId->Enabled = false;
			this->txtId->Location = System::Drawing::Point(137, 41);
			this->txtId->Margin = System::Windows::Forms::Padding(2);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(127, 20);
			this->txtId->TabIndex = 6;
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
			this->ClientSize = System::Drawing::Size(327, 388);
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
		nuevoUsuario->SetId(Convert::ToInt32(txtId->Text));
		nuevoUsuario->SetNombre(txtNombre->Text);
		nuevoUsuario->SetEmail(txtCorreo->Text);
		nuevoUsuario->SetContrasenha(txtCtrsn->Text);
		nuevoUsuario->SetRol(rolController->obtenerRolPorNombre(comboBox1->Text));
		nuevoUsuario->SetUltimoAcceso("-"); // Inicialmente vacío
		nuevoUsuario->SetEstadoCuenta("Activo"); // Estado por defecto
		
		// Llamar al controlador para agregar el nuevo usuario
		this->usuarioController->agregarUsuario(nuevoUsuario);
		
		// Confirmación
		MessageBox::Show("Usuario agregado correctamente.", "Nuevo Usuario", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
		   //===============================================================================
		   //==============================Cancelar=========================================
		   //===============================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e){
		this->Close();
	}

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
		/*crea un ID automático*/
		List<Usuario^>^ listaUsuarios = this->usuarioController->obtenerTodosUsuarios();

		int maxId = 0;
		for each(Usuario ^ usuario in listaUsuarios) {
			if (usuario->GetId() > maxId) {
				maxId = usuario->GetId();
			}
		}
		this->txtId->Text = Convert::ToString(maxId + 1);

	}
};
}
