#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmRendimiento
	/// </summary>
	public ref class frmRendimiento : public System::Windows::Forms::Form
	{
	public:
		frmRendimiento(RendimientoController^ rendimientoController)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->rendimientoController = rendimientoController;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmRendimiento()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ProgressBar^ progressBar3;
	private: RendimientoController^ rendimientoController;
	private: System::Windows::Forms::Label^ txtIzq;
	private: System::Windows::Forms::Label^ txtVidaIzq;
	private: System::Windows::Forms::Label^ txtVidaDer;
	private: System::Windows::Forms::Label^ txtCiclos;
	private: System::Windows::Forms::Label^ txtPorcIzq;
	private: System::Windows::Forms::Label^ txtPorcDer;
	private: System::Windows::Forms::Label^ txtPorcCiclos;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btnReemplazarIzq;
	private: System::Windows::Forms::Button^ btnReemplazarDer;
	private: System::Windows::Forms::Button^ btnReemplazarServo;




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
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->txtIzq = (gcnew System::Windows::Forms::Label());
			this->txtVidaIzq = (gcnew System::Windows::Forms::Label());
			this->txtVidaDer = (gcnew System::Windows::Forms::Label());
			this->txtCiclos = (gcnew System::Windows::Forms::Label());
			this->txtPorcIzq = (gcnew System::Windows::Forms::Label());
			this->txtPorcDer = (gcnew System::Windows::Forms::Label());
			this->txtPorcCiclos = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnReemplazarIzq = (gcnew System::Windows::Forms::Button());
			this->btnReemplazarDer = (gcnew System::Windows::Forms::Button());
			this->btnReemplazarServo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(114, 29);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(198, 23);
			this->progressBar1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 94);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Motor Derecho:";
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(114, 89);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(198, 23);
			this->progressBar2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Servomotor:";
			// 
			// progressBar3
			// 
			this->progressBar3->Location = System::Drawing::Point(114, 149);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(198, 23);
			this->progressBar3->TabIndex = 5;
			// 
			// txtIzq
			// 
			this->txtIzq->AutoSize = true;
			this->txtIzq->Location = System::Drawing::Point(15, 34);
			this->txtIzq->Name = L"txtIzq";
			this->txtIzq->Size = System::Drawing::Size(83, 13);
			this->txtIzq->TabIndex = 0;
			this->txtIzq->Text = L"Motor Izquierdo:";
			// 
			// txtVidaIzq
			// 
			this->txtVidaIzq->AutoSize = true;
			this->txtVidaIzq->Location = System::Drawing::Point(204, 55);
			this->txtVidaIzq->Name = L"txtVidaIzq";
			this->txtVidaIzq->Size = System::Drawing::Size(29, 13);
			this->txtVidaIzq->TabIndex = 6;
			this->txtVidaIzq->Text = L"label";
			// 
			// txtVidaDer
			// 
			this->txtVidaDer->AutoSize = true;
			this->txtVidaDer->Location = System::Drawing::Point(204, 115);
			this->txtVidaDer->Name = L"txtVidaDer";
			this->txtVidaDer->Size = System::Drawing::Size(29, 13);
			this->txtVidaDer->TabIndex = 7;
			this->txtVidaDer->Text = L"label";
			// 
			// txtCiclos
			// 
			this->txtCiclos->AutoSize = true;
			this->txtCiclos->Location = System::Drawing::Point(204, 175);
			this->txtCiclos->Name = L"txtCiclos";
			this->txtCiclos->Size = System::Drawing::Size(29, 13);
			this->txtCiclos->TabIndex = 8;
			this->txtCiclos->Text = L"label";
			// 
			// txtPorcIzq
			// 
			this->txtPorcIzq->AutoSize = true;
			this->txtPorcIzq->Location = System::Drawing::Point(318, 34);
			this->txtPorcIzq->Name = L"txtPorcIzq";
			this->txtPorcIzq->Size = System::Drawing::Size(35, 13);
			this->txtPorcIzq->TabIndex = 9;
			this->txtPorcIzq->Text = L"label3";
			// 
			// txtPorcDer
			// 
			this->txtPorcDer->AutoSize = true;
			this->txtPorcDer->Location = System::Drawing::Point(318, 94);
			this->txtPorcDer->Name = L"txtPorcDer";
			this->txtPorcDer->Size = System::Drawing::Size(35, 13);
			this->txtPorcDer->TabIndex = 10;
			this->txtPorcDer->Text = L"label4";
			// 
			// txtPorcCiclos
			// 
			this->txtPorcCiclos->AutoSize = true;
			this->txtPorcCiclos->Location = System::Drawing::Point(318, 154);
			this->txtPorcCiclos->Name = L"txtPorcCiclos";
			this->txtPorcCiclos->Size = System::Drawing::Size(35, 13);
			this->txtPorcCiclos->TabIndex = 11;
			this->txtPorcCiclos->Text = L"label5";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(193, 216);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmRendimiento::button1_Click);
			// 
			// btnReemplazarIzq
			// 
			this->btnReemplazarIzq->Location = System::Drawing::Point(372, 29);
			this->btnReemplazarIzq->Name = L"btnReemplazarIzq";
			this->btnReemplazarIzq->Size = System::Drawing::Size(74, 23);
			this->btnReemplazarIzq->TabIndex = 13;
			this->btnReemplazarIzq->Text = L"Reemplazar";
			this->btnReemplazarIzq->UseVisualStyleBackColor = true;
			this->btnReemplazarIzq->Click += gcnew System::EventHandler(this, &frmRendimiento::btnReemplazarIzq_Click);
			// 
			// btnReemplazarDer
			// 
			this->btnReemplazarDer->Location = System::Drawing::Point(372, 89);
			this->btnReemplazarDer->Name = L"btnReemplazarDer";
			this->btnReemplazarDer->Size = System::Drawing::Size(74, 23);
			this->btnReemplazarDer->TabIndex = 14;
			this->btnReemplazarDer->Text = L"Reemplazar";
			this->btnReemplazarDer->UseVisualStyleBackColor = true;
			this->btnReemplazarDer->Click += gcnew System::EventHandler(this, &frmRendimiento::btnReemplazarDer_Click);
			// 
			// btnReemplazarServo
			// 
			this->btnReemplazarServo->Location = System::Drawing::Point(372, 149);
			this->btnReemplazarServo->Name = L"btnReemplazarServo";
			this->btnReemplazarServo->Size = System::Drawing::Size(74, 23);
			this->btnReemplazarServo->TabIndex = 15;
			this->btnReemplazarServo->Text = L"Reemplazar";
			this->btnReemplazarServo->UseVisualStyleBackColor = true;
			this->btnReemplazarServo->Click += gcnew System::EventHandler(this, &frmRendimiento::btnReemplazarServo_Click);
			// 
			// frmRendimiento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 258);
			this->Controls->Add(this->btnReemplazarServo);
			this->Controls->Add(this->btnReemplazarDer);
			this->Controls->Add(this->btnReemplazarIzq);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtPorcCiclos);
			this->Controls->Add(this->txtPorcDer);
			this->Controls->Add(this->txtPorcIzq);
			this->Controls->Add(this->txtCiclos);
			this->Controls->Add(this->txtVidaDer);
			this->Controls->Add(this->txtVidaIzq);
			this->Controls->Add(this->progressBar3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->txtIzq);
			this->Name = L"frmRendimiento";
			this->Text = L"Rendimiento de Motores";
			this->Load += gcnew System::EventHandler(this, &frmRendimiento::frmRendimiento_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void actualizarBarra() {
		//FUNCIÓN PARA ACTUALIZAR LA BARRA AL MISMO TIEMPO QUE SE REEMPLAZA EL MOTOR
	}

	private: System::Void frmRendimiento_Load(System::Object^ sender, System::EventArgs^ e) {
		Rendimiento^ rendimiento = this->rendimientoController->buscarTodos()[0];

		double vidaRestanteIzq = rendimiento->getVidaUtilEstimadaMotor() - rendimiento->getHorasMotorIzquierdo();
		double vidaRestanteDer = rendimiento->getVidaUtilEstimadaMotor() - rendimiento->getHorasMotorDerecho();
		long ciclosRestantes = rendimiento->getVidaUtilEstimadaServo() - rendimiento->getCiclosOperacionServo();

		//Porcentajes
		double porcentajeIzq = (vidaRestanteIzq / rendimiento->getVidaUtilEstimadaMotor()) * 100.0;
		double porcentajeDer = (vidaRestanteDer / rendimiento->getVidaUtilEstimadaMotor()) * 100.0;
		double porcentajeServo = ((double)ciclosRestantes / rendimiento->getVidaUtilEstimadaServo()) * 100.0;

		// Asegurarse de que el valor no sea negativo ni exceda 100
		int valorBarraIzq = Math::Max(0, Math::Min(100, (int)porcentajeIzq));
		int valorBarraDer = Math::Max(0, Math::Min(100, (int)porcentajeDer));
		int valorBarraServo = Math::Max(0, Math::Min(100, (int)porcentajeServo));
		
		// Asignar el valor de porcentaje a la barra de progreso
		this->progressBar1->Value = valorBarraIzq;
		this->progressBar2->Value = valorBarraDer;
		this->progressBar3->Value = valorBarraServo;

		//Textos
		this->txtVidaIzq->Text = String::Format("{0:N2} horas restantes", vidaRestanteIzq);
		this->txtPorcIzq->Text = String::Format("{0:N2}%", porcentajeIzq);
		this->txtVidaDer->Text = String::Format("{0:N2} horas restantes", vidaRestanteDer);
		this->txtPorcDer->Text = String::Format("{0:N2}%", porcentajeDer);
		this->txtCiclos->Text = String::Format("{0} ciclos restantes", ciclosRestantes);
		this->txtPorcCiclos->Text = String::Format("{0:N2}%", porcentajeServo);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	
	private: System::Void btnReemplazarIzq_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult resultado = System::Windows::Forms::MessageBox::Show(
			"Está seguro que el motor izquierdo ha sido cambiado correctamente?",
			"Confirmar Mantenimiento del Motor Izquierdo",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Warning
		);
		
		if (resultado == System::Windows::Forms::DialogResult::Yes) {
			this->rendimientoController->buscarTodos()[0]->setHorasMotorIzquierdo(0);
			this->rendimientoController->escribirArchivo();


		}
	}

	private: System::Void btnReemplazarDer_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult resultado = System::Windows::Forms::MessageBox::Show(
			"Está seguro que el motor derecho ha sido cambiado correctamente?",
			"Confirmar Mantenimiento del Motor Derecho",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Warning
		);
		
		if (resultado == System::Windows::Forms::DialogResult::Yes) {
			this->rendimientoController->buscarTodos()[0]->setHorasMotorDerecho(0);
			this->rendimientoController->escribirArchivo();


		}
	}

	private: System::Void btnReemplazarServo_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult resultado = System::Windows::Forms::MessageBox::Show(
			"Está seguro que el servomotor ha sido cambiado correctamente?",
			"Confirmar Mantenimiento del Servomotor",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Warning
		);
		
		if (resultado == System::Windows::Forms::DialogResult::Yes) {
			this->rendimientoController->buscarTodos()[0]->setCiclosOperacionServo(0);
			this->rendimientoController->escribirArchivo();


		}
	}
};
}
