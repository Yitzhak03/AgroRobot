#pragma once

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
	/// Resumen de frmEditarUsuario
	/// </summary>
	public ref class frmEditarUsuario : public System::Windows::Forms::Form
	{
	public:
		frmEditarUsuario(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmEditarUsuario(UsuarioController^ usuarioController, Usuario^ usuario)
		{
			InitializeComponent();
			this->usuarioController = usuarioController;
			this->usuario = usuario;
			this->rolController = rolController;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarUsuario()
		{
			if (components)
			{
				delete components;
			}
		}

	private: UsuarioController^ usuarioController;
	private: Usuario^ usuario;
	private: RolController^ rolController;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtId;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtCtrsn;


	private: System::Windows::Forms::TextBox^ txtCorreo;


	private: System::Windows::Forms::Button^ btnGrabar;

	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::ComboBox^ txtRoles;















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
			this->txtRoles = (gcnew System::Windows::Forms::ComboBox());
			this->txtCtrsn = (gcnew System::Windows::Forms::TextBox());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtRoles);
			this->groupBox1->Controls->Add(this->txtCtrsn);
			this->groupBox1->Controls->Add(this->txtCorreo);
			this->groupBox1->Controls->Add(this->txtNombre);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->txtId);
			this->groupBox1->Location = System::Drawing::Point(11, 11);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(304, 320);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos de Usuario";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmEditarUsuario::groupBox1_Enter);
			// 
			// txtRoles
			// 
			this->txtRoles->FormattingEnabled = true;
			this->txtRoles->Location = System::Drawing::Point(137, 222);
			this->txtRoles->Name = L"txtRoles";
			this->txtRoles->Size = System::Drawing::Size(127, 21);
			this->txtRoles->TabIndex = 11;
			// 
			// txtCtrsn
			// 
			this->txtCtrsn->Location = System::Drawing::Point(137, 178);
			this->txtCtrsn->Name = L"txtCtrsn";
			this->txtCtrsn->Size = System::Drawing::Size(127, 20);
			this->txtCtrsn->TabIndex = 10;
			// 
			// txtCorreo
			// 
			this->txtCorreo->Location = System::Drawing::Point(137, 129);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(127, 20);
			this->txtCorreo->TabIndex = 9;
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(137, 85);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(127, 20);
			this->txtNombre->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(41, 225);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Roles:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 181);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Contraseña:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(41, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Correo:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Nombre:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Id:";
			this->label2->Click += gcnew System::EventHandler(this, &frmEditarUsuario::label2_Click);
			// 
			// txtId
			// 
			this->txtId->Enabled = false;
			this->txtId->Location = System::Drawing::Point(137, 41);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(127, 20);
			this->txtId->TabIndex = 2;
			// 
			// btnGrabar
			// 
			this->btnGrabar->Location = System::Drawing::Point(77, 348);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(56, 19);
			this->btnGrabar->TabIndex = 1;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = true;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmEditarUsuario::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(148, 348);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(66, 19);
			this->btnCancelar->TabIndex = 2;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmEditarUsuario::btnCancelar_Click);
			// 
			// frmEditarUsuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(327, 388);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmEditarUsuario";
			this->Text = L"frmEditarUsuario";
			this->Load += gcnew System::EventHandler(this, &frmEditarUsuario::frmEditarUsuario_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEditarUsuario_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargar los datos del objeto Operador en los controles del formulario
		this->txtId->Text = this->usuario->GetId().ToString();
		this->txtNombre->Text = this->usuario->GetNombre();
		this->txtCorreo->Text = this->usuario->GetEmail();
		this->txtCtrsn->Text = this->usuario->GetContrasenha();
		this->txtRoles->Text = this->usuario->GetRol()->GetNombre();
	}

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		Usuario^ nuevoUsuario = gcnew Usuario();
		nuevoUsuario->SetId(Convert::ToInt32(txtId->Text));
		nuevoUsuario->SetNombre(txtNombre->Text);
		nuevoUsuario->SetEmail(txtCorreo->Text);
		nuevoUsuario->SetContrasenha(txtCtrsn->Text);
		nuevoUsuario->SetRol(rolController->obtenerRolPorNombre(txtRoles->Text));
		nuevoUsuario->SetUltimoAcceso(""); // Inicialmente vacío
		nuevoUsuario->SetEstadoCuenta("Activo"); // Estado por defecto
		// Llamando al controlador para actualizar el operador en la base de datos
		
		this->usuarioController->actualizarUsuario(nuevoUsuario);
		MessageBox::Show("El usuario se actualizó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close(); // Cierra el formulario actual
	}
};
}
