#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Resumen de frmMantReporteDiagnostico
	/// </summary>
	public ref class frmMantReporteDiagnostico : public System::Windows::Forms::Form
	{
	public:
		frmMantReporteDiagnostico(void)
		{
			InitializeComponent();
			this->reporteController = gcnew ReporteDiagnosticoController();
			this->pdfExportController = gcnew PdfExportServiceController();
			this->reporteActual = nullptr;
			/*
			// Configurar event handlers como en frmMantReporteAlimentacion
			//this->button1->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button1_Click);
			this->button3->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button3_Click);
			this->button2->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button2_Click);
			this->button4->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button4_Click);
			this->button5->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button5_Click);
			this->radioMensual->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::radioMensual_CheckedChanged);
			this->radioRango->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::radioRango_CheckedChanged);
			*/

			ConfigurarControlesIniciales();
			ConfigurarCharts();

			// Agregar tooltips como en la referencia
			ConfigurarToolTips();
			AplicarEstiloProfesional();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantReporteDiagnostico()
		{
			// Liberar recursos como en la referencia
			if (reporteController != nullptr) {
				delete reporteController;
				reporteController = nullptr;
			}
			if (pdfExportController != nullptr) {
				delete pdfExportController;
				pdfExportController = nullptr;
			}
			if (reporteActual != nullptr) {
				delete reporteActual;
				reporteActual = nullptr;
			}
			if (components)
			{
				delete components;
			}
		}

	private:
		// Controles existentes
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::DateTimePicker^ dateTimePicker2;
		System::Windows::Forms::DateTimePicker^ dateTimePicker1;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::GroupBox^ groupBox2;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TabControl^ tabControl1;
		System::Windows::Forms::TabPage^ tabPage1;
		System::Windows::Forms::TabPage^ tabPage2;
		System::Windows::Forms::TabPage^ tabPage3;
		System::Windows::Forms::GroupBox^ groupBox3;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button2;

		// Nuevos controles
		ReporteDiagnosticoController^ reporteController;
		PdfExportServiceController^ pdfExportController;
		ReporteDiagnosticoResult^ reporteActual;
		Chart^ chartTipoAnalisis;
		Chart^ chartEstadoSalud;
		System::Windows::Forms::DataGridView^ dataGridEstadisticas;
		System::Windows::Forms::DataGridView^ dataGridDetalle;
		System::Windows::Forms::ComboBox^ comboAnio;
		System::Windows::Forms::ComboBox^ comboMes;
		System::Windows::Forms::RadioButton^ radioMensual;
		System::Windows::Forms::RadioButton^ radioRango;

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
			this->chartTipoAnalisis = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartEstadoSalud = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioMensual = (gcnew System::Windows::Forms::RadioButton());
			this->radioRango = (gcnew System::Windows::Forms::RadioButton());
			this->comboAnio = (gcnew System::Windows::Forms::ComboBox());
			this->comboMes = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridEstadisticas = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTipoAnalisis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstadoSalud))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEstadisticas))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDetalle))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// chartTipoAnalisis
			// 
			this->chartTipoAnalisis->Location = System::Drawing::Point(10, 10);
			this->chartTipoAnalisis->Name = L"chartTipoAnalisis";
			this->chartTipoAnalisis->Size = System::Drawing::Size(380, 140);
			this->chartTipoAnalisis->TabIndex = 0;
			this->chartTipoAnalisis->Text = L"Tipos de Análisis";
			// 
			// chartEstadoSalud
			// 
			this->chartEstadoSalud->Location = System::Drawing::Point(10, 160);
			this->chartEstadoSalud->Name = L"chartEstadoSalud";
			this->chartEstadoSalud->Size = System::Drawing::Size(380, 130);
			this->chartEstadoSalud->TabIndex = 1;
			this->chartEstadoSalud->Text = L"Estados de Salud";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->groupBox1->Controls->Add(this->radioMensual);
			this->groupBox1->Controls->Add(this->radioRango);
			this->groupBox1->Controls->Add(this->comboAnio);
			this->groupBox1->Controls->Add(this->comboMes);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->dateTimePicker2);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->groupBox1->Location = System::Drawing::Point(35, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(408, 134);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de búsqueda";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::groupBox1_Enter);
			// 
			// radioMensual
			// 
			this->radioMensual->AutoSize = true;
			this->radioMensual->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioMensual->Location = System::Drawing::Point(24, 60);
			this->radioMensual->Name = L"radioMensual";
			this->radioMensual->Size = System::Drawing::Size(71, 19);
			this->radioMensual->TabIndex = 14;
			this->radioMensual->TabStop = true;
			this->radioMensual->Text = L"Mensual";
			this->radioMensual->UseVisualStyleBackColor = true;
			this->radioMensual->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::radioMensual_CheckedChanged);
			// 
			// radioRango
			// 
			this->radioRango->AutoSize = true;
			this->radioRango->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioRango->Location = System::Drawing::Point(24, 35);
			this->radioRango->Name = L"radioRango";
			this->radioRango->Size = System::Drawing::Size(59, 19);
			this->radioRango->TabIndex = 15;
			this->radioRango->Text = L"Rango";
			this->radioRango->UseVisualStyleBackColor = true;
			this->radioRango->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::radioRango_CheckedChanged);
			// 
			// comboAnio
			// 
			this->comboAnio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->comboAnio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboAnio->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->comboAnio->FormattingEnabled = true;
			this->comboAnio->Location = System::Drawing::Point(104, 58);
			this->comboAnio->Name = L"comboAnio";
			this->comboAnio->Size = System::Drawing::Size(70, 23);
			this->comboAnio->TabIndex = 16;
			// 
			// comboMes
			// 
			this->comboMes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->comboMes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboMes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->comboMes->FormattingEnabled = true;
			this->comboMes->Location = System::Drawing::Point(184, 58);
			this->comboMes->Name = L"comboMes";
			this->comboMes->Size = System::Drawing::Size(100, 23);
			this->comboMes->TabIndex = 17;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(214, 96);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 23);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Limpiar";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button3_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(108, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(231, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 15);
			this->label5->TabIndex = 8;
			this->label5->Text = L"a";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 15);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Rango:";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker2->Location = System::Drawing::Point(261, 33);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(121, 22);
			this->dateTimePicker2->TabIndex = 6;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(91, 33);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(121, 22);
			this->dateTimePicker1->TabIndex = 2;
			this->dateTimePicker1->Value = System::DateTime(2022, 1, 1, 0, 0, 0, 0);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->groupBox2->Location = System::Drawing::Point(35, 177);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(408, 116);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Resumen Ejecutivo";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::groupBox2_Enter);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->textBox4->Location = System::Drawing::Point(327, 75);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(56, 22);
			this->textBox4->TabIndex = 10;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->textBox3->Location = System::Drawing::Point(230, 75);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(56, 22);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->textBox1->Location = System::Drawing::Point(130, 75);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(58, 22);
			this->textBox1->TabIndex = 8;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(324, 45);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Heces";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(227, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Sangre";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(127, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 34);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Animales\r\nÚnicos";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->textBox2->Location = System::Drawing::Point(27, 75);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(55, 22);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(24, 28);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(71, 34);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Total\r\nMuestras";
			this->label6->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::label6_Click_1);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(470, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(408, 363);
			this->tabControl1->TabIndex = 5;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->chartTipoAnalisis);
			this->tabPage1->Controls->Add(this->chartEstadoSalud);
			this->tabPage1->Location = System::Drawing::Point(4, 24);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(400, 335);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Gráficos";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridEstadisticas);
			this->tabPage2->Location = System::Drawing::Point(4, 24);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(400, 335);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Estadísticas";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridEstadisticas
			// 
			this->dataGridEstadisticas->AllowUserToAddRows = false;
			this->dataGridEstadisticas->AllowUserToDeleteRows = false;
			this->dataGridEstadisticas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridEstadisticas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridEstadisticas->Location = System::Drawing::Point(3, 3);
			this->dataGridEstadisticas->Name = L"dataGridEstadisticas";
			this->dataGridEstadisticas->ReadOnly = true;
			this->dataGridEstadisticas->Size = System::Drawing::Size(394, 329);
			this->dataGridEstadisticas->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridDetalle);
			this->tabPage3->Location = System::Drawing::Point(4, 24);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(400, 335);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Detalle";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridDetalle
			// 
			this->dataGridDetalle->AllowUserToAddRows = false;
			this->dataGridDetalle->AllowUserToDeleteRows = false;
			this->dataGridDetalle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridDetalle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridDetalle->Location = System::Drawing::Point(0, 0);
			this->dataGridDetalle->Name = L"dataGridDetalle";
			this->dataGridDetalle->ReadOnly = true;
			this->dataGridDetalle->Size = System::Drawing::Size(400, 335);
			this->dataGridDetalle->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->groupBox3->Location = System::Drawing::Point(35, 314);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(408, 73);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Exportar a:";
			this->groupBox3->Enter += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::groupBox3_Enter);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(176)));
			this->button5->Location = System::Drawing::Point(298, 29);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 23);
			this->button5->TabIndex = 15;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Location = System::Drawing::Point(172, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Excel";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button4_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(40, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"TXT";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button2_Click);
			// 
			// frmMantReporteDiagnostico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(904, 413);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantReporteDiagnostico";
			this->Text = L"Reporte de Diagnóstico Médico";
			this->Load += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::frmMantReporteDiagnostico_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTipoAnalisis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstadoSalud))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEstadisticas))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDetalle))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void frmMantReporteDiagnostico_Load(System::Object^ sender, System::EventArgs^ e) {
		}

		System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			GenerarReporte();
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			LimpiarControles();
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			ExportarPDF();
		}

		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			ExportarExcel();
		}

		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void radioMensual_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			HabilitarControlesMensual();
		}

		System::Void radioRango_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			HabilitarControlesRango();
		}

	private:
		void ConfigurarControlesIniciales() {
			// 1. Configurar Años: Aseguramos que 2025 esté en la lista
			comboAnio->Items->Clear();
			int anioBase = 2025;
			// Agregamos desde 2022 hasta 2026 para tener margen
			for (int i = 2022; i <= 2026; i++) {
				comboAnio->Items->Add(i.ToString());
			}

			// SELECCIONAR 2025 POR DEFECTO
			comboAnio->SelectedItem = "2025";

			// 2. Configurar Meses
			comboMes->Items->Clear();
			array<String^>^ meses = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
									"Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
			comboMes->Items->AddRange(meses);

			// SELECCIONAR OCTUBRE (Índice 9 porque empieza en 0)
			comboMes->SelectedIndex = 9;

			// 3. Configurar Rango de Fechas (1 al 31 de Octubre de 2025)
			dateTimePicker1->Value = DateTime(2025, 10, 1);
			dateTimePicker2->Value = DateTime(2025, 10, 31);

			// 4. Activar Mensual por defecto
			radioMensual->Checked = true;
			HabilitarControlesMensual();
		}

		void HabilitarControlesMensual() {
			comboAnio->Enabled = true;
			comboMes->Enabled = true;
			dateTimePicker1->Enabled = false;
			dateTimePicker2->Enabled = false;
		}

		void HabilitarControlesRango() {
			comboAnio->Enabled = false;
			comboMes->Enabled = false;
			dateTimePicker1->Enabled = true;
			dateTimePicker2->Enabled = true;
		}

		void GenerarReporte() {
			try {
				// Validar criterio de búsqueda (como en la referencia)
				if (!radioMensual->Checked && !radioRango->Checked) {
					MessageBox::Show("Por favor seleccione un criterio de búsqueda (Mensual o Rango)",
						"Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				if (radioMensual->Checked) {
					// Validar selección de año y mes
					if (comboAnio->SelectedItem == nullptr || comboMes->SelectedItem == nullptr) {
						MessageBox::Show("Por favor seleccione año y mes", "Validación",
							MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}

					int año = Convert::ToInt32(comboAnio->SelectedItem);
					int mes = comboMes->SelectedIndex + 1;
					reporteActual = reporteController->GenerarReporteMensual(año, mes);
				}
				else {
					// Validar rango de fechas
					if (dateTimePicker1->Value > dateTimePicker2->Value) {
						MessageBox::Show("La fecha de inicio no puede ser mayor que la fecha fin",
							"Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}

					String^ fechaInicio = dateTimePicker1->Value.ToString("yyyy-MM-dd");
					String^ fechaFin = dateTimePicker2->Value.ToString("yyyy-MM-dd");
					reporteActual = reporteController->GenerarReportePorRangoFechas(fechaInicio, fechaFin);
				}

				// Verificar si hay datos
				if (reporteActual != nullptr && reporteActual->TotalMuestras == 0) {
					MessageBox::Show("No se encontraron muestras para los criterios seleccionados",
						"Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}

				ActualizarResumen();
				ActualizarGraficos();
				ActualizarEstadisticas();
				ActualizarDetalle();

			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al generar reporte: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void ActualizarResumen() {
			if (reporteActual == nullptr) return;

			textBox2->Text = reporteActual->TotalMuestras.ToString();
			textBox1->Text = reporteActual->TotalAnimales.ToString();

			// Calcular muestras por tipo
			int sangre = 0, heces = 0;
			for each (auto stat in reporteActual->PorTipoAnalisis) {
				if (stat->Categoria == "Sangre") sangre = stat->Cantidad;
				else if (stat->Categoria == "Heces") heces = stat->Cantidad;
			}

			textBox3->Text = sangre.ToString();
			textBox4->Text = heces.ToString();
		}

		void ActualizarGraficos() {
			if (reporteActual == nullptr) return;

			try {
				// --- 1. ACTUALIZAR BARRAS (Tipos) - IGUAL ---
				chartTipoAnalisis->Series->Clear();
				if (reporteActual->PorTipoAnalisis->Count > 0) {
					Series^ seriesTipos = gcnew Series("TiposAnalisis");
					seriesTipos->ChartType = SeriesChartType::Column;
					seriesTipos->IsValueShownAsLabel = true;
					seriesTipos->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
					seriesTipos->LabelForeColor = System::Drawing::Color::Black;

					chartTipoAnalisis->Series->Add(seriesTipos);

					for each (auto stat in reporteActual->PorTipoAnalisis) {
						DataPoint^ point = gcnew DataPoint();
						point->SetValueXY(stat->Categoria, stat->Cantidad);
						point->ToolTip = stat->Categoria + ": " + stat->Cantidad + " muestras";
						chartTipoAnalisis->Series["TiposAnalisis"]->Points->Add(point);
					}
				}

				// --- 2. ACTUALIZAR PASTEL (Estado de Salud) - CORREGIDO ---
				chartEstadoSalud->Series->Clear();

				// IMPORTANTE: Asegurar que NO sea 3D para que salgan las líneas
				if (chartEstadoSalud->ChartAreas->Count > 0)
					chartEstadoSalud->ChartAreas[0]->Area3DStyle->Enable3D = false;

				if (reporteActual->PorEstadoSalud->Count > 0) {
					Series^ seriesEstados = gcnew Series("EstadosSalud");
					seriesEstados->ChartType = SeriesChartType::Pie;

					// 1. CONTENIDO: Solo el nombre
					seriesEstados->Label = "#AXISLABEL";

					// 2. TAMAÑO: Letra un poco más grande (11)
					seriesEstados->Font = gcnew System::Drawing::Font("Arial", 11, FontStyle::Bold);

					// 3. ESTILO: Sacar etiquetas afuera con línea negra
					seriesEstados->SetCustomProperty("PieLabelStyle", "Outside");
					seriesEstados->SetCustomProperty("PieLineColor", "Black");

					// 4. LEYENDA: Mantenemos el detalle
					seriesEstados->LegendText = "#AXISLABEL (#PERCENT)";
					seriesEstados->Legend = "LeyendaSalud";

					chartEstadoSalud->Series->Add(seriesEstados);

					for each (auto stat in reporteActual->PorEstadoSalud) {
						DataPoint^ point = gcnew DataPoint();

						point->SetValueXY(stat->Categoria, stat->Cantidad);
						point->AxisLabel = stat->Categoria;
						point->ToolTip = stat->Categoria + ": " + stat->Cantidad + " (" + stat->Porcentaje.ToString("F1") + "%)";

						if (stat->Categoria->ToLower() == "crítico" || stat->Categoria->ToLower() == "critico") {
							point->SetCustomProperty("Exploded", "true");
						}

						chartEstadoSalud->Series["EstadosSalud"]->Points->Add(point);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error visual: " + ex->Message);
			}
		}

		void ActualizarEstadisticas() {
			if (reporteActual == nullptr) return;

			// Configurar DataGridView de estadísticas
			dataGridEstadisticas->Rows->Clear();
			dataGridEstadisticas->Columns->Clear();

			// Agregar columnas
			dataGridEstadisticas->Columns->Add("Categoria", "Categoría");
			dataGridEstadisticas->Columns->Add("Cantidad", "Cantidad");
			dataGridEstadisticas->Columns->Add("Porcentaje", "Porcentaje");

			// Agregar datos de tipos de análisis (sin título redundante)
			for each (auto stat in reporteActual->PorTipoAnalisis) {
				dataGridEstadisticas->Rows->Add(stat->Categoria, stat->Cantidad, stat->Porcentaje.ToString("F1") + "%");
			}

			// Agregar datos de estados de salud (sin título redundante)
			for each (auto stat in reporteActual->PorEstadoSalud) {
				dataGridEstadisticas->Rows->Add(stat->Categoria, stat->Cantidad, stat->Porcentaje.ToString("F1") + "%");
			}

			// Configurar para que ocupe todo el espacio disponible
			dataGridEstadisticas->Dock = DockStyle::Fill;
			dataGridEstadisticas->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			// Hacer que la primera columna sea más ancha para los textos largos
			if (dataGridEstadisticas->Columns->Count > 0) {
				dataGridEstadisticas->Columns[0]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			}

		}


		void ActualizarDetalle() {
			if (reporteActual == nullptr) return;

			dataGridDetalle->Rows->Clear();
			dataGridDetalle->Columns->Clear();

			// Agregar columnas con mejor configuración
			dataGridDetalle->Columns->Add("Numero", "N°");
			dataGridDetalle->Columns->Add("Detalle", "Detalle de Muestra");

			// Configurar para que ocupe todo el espacio disponible
			dataGridDetalle->Dock = DockStyle::Fill;
			dataGridDetalle->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			// Agregar datos
			for (int i = 0; i < reporteActual->MuestrasResumen->Count; i++) {
				dataGridDetalle->Rows->Add((i + 1).ToString(), reporteActual->MuestrasResumen[i]);
			}
		}

		void LimpiarControles() {
			textBox2->Text = "";
			textBox1->Text = "";
			textBox3->Text = "";
			textBox4->Text = "";

			chartTipoAnalisis->Series->Clear();
			chartEstadoSalud->Series->Clear();

			dataGridEstadisticas->Rows->Clear();
			dataGridDetalle->Rows->Clear();

			reporteActual = nullptr;
		}

		void ExportarPDF() {
			if (reporteActual == nullptr) {
				MessageBox::Show("Primero genere un reporte (Botón Buscar).", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			// TRUCO: Guardamos como .txt para que sea legible, aunque el botón diga PDF
			saveDialog->Filter = "Reporte Texto|*.txt";
			saveDialog->Title = "Guardar Reporte";
			saveDialog->FileName = "Reporte_" + DateTime::Now.ToString("yyyyMMdd_HHmm") + ".txt";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				bool exito = pdfExportController->ExportarReporteDiagnosticoPDF(reporteActual, saveDialog->FileName);

				if (exito) {
					MessageBox::Show("Reporte guardado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
					// Opcional: Abrir el archivo automáticamente
					// System::Diagnostics::Process::Start(saveDialog->FileName);
				}
				else {
					MessageBox::Show("No se pudo guardar el archivo. Verifique permisos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		void ExportarExcel() {
			if (reporteActual == nullptr) {
				MessageBox::Show("Primero genere un reporte (Botón Buscar).", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivo Excel CSV|*.csv";
			saveDialog->Title = "Guardar Excel";
			saveDialog->FileName = "Data_" + DateTime::Now.ToString("yyyyMMdd_HHmm") + ".csv";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				bool exito = pdfExportController->ExportarReporteDiagnosticoExcel(reporteActual, saveDialog->FileName);

				if (exito) {
					MessageBox::Show("Excel generado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Error al generar Excel. ¿Tiene el archivo abierto?", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		private:
			void ConfigurarToolTips() {
				ToolTip^ toolTip = gcnew ToolTip();
				toolTip->SetToolTip(button1, "Generar reporte con los criterios seleccionados");
				toolTip->SetToolTip(button3, "Limpiar todos los filtros y resultados");
				toolTip->SetToolTip(button2, "Exportar reporte a formato PDF");
				toolTip->SetToolTip(button4, "Exportar reporte a formato Excel");
				toolTip->SetToolTip(button5, "Cerrar la ventana de reportes");
				toolTip->SetToolTip(comboAnio, "Seleccionar año para reporte mensual");
				toolTip->SetToolTip(comboMes, "Seleccionar mes para reporte mensual");
				toolTip->SetToolTip(radioMensual, "Generar reporte por mes específico");
				toolTip->SetToolTip(radioRango, "Generar reporte por rango de fechas");
			}

		private:
			void AplicarEstiloProfesional() {
				// Colores
				System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(238, 245, 233);
				System::Drawing::Color colorVerde = System::Drawing::Color::FromArgb(67, 160, 71);
				System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(30, 60, 30);
				System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Regular);
				System::Drawing::Font^ fuenteBold = gcnew System::Drawing::Font("Segoe UI Semibold", 9, FontStyle::Bold);

				// Ventana
				this->BackgroundImage = nullptr;
				this->BackColor = colorFondo;
				this->Font = fuente;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				this->AutoSize = false;
				this->Dock = DockStyle::Fill;

				// Pestañas (Responsive)
				tabControl1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);
				tabPage1->BackColor = colorFondo;
				tabPage2->BackColor = System::Drawing::Color::White;
				tabPage3->BackColor = System::Drawing::Color::White;

				// Paneles Izquierda (Fijos)
				groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
				groupBox2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
				groupBox3->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left); // Panel de exportar

				// Estilo GroupBoxes
				array<GroupBox^>^ grupos = { groupBox1, groupBox2, groupBox3 };
				for each (GroupBox ^ gb in grupos) {
					gb->BackColor = System::Drawing::Color::White;
					gb->ForeColor = colorTexto;
					gb->Font = fuenteBold;
					gb->FlatStyle = FlatStyle::System;
				}

				// Botones Acción (Arriba izquierda)
				array<Button^>^ botones = { button1, button2, button3, button4 };
				for each (Button ^ b in botones) {
					b->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
					b->BackColor = colorVerde;
					b->ForeColor = System::Drawing::Color::White;
					b->FlatStyle = FlatStyle::Flat;
					b->FlatAppearance->BorderSize = 0;
					b->Font = fuenteBold;
					b->Cursor = Cursors::Hand;
				}
				// Cancelar Gris
				button5->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
				button5->BackColor = System::Drawing::Color::FromArgb(200, 200, 200);
				button5->ForeColor = System::Drawing::Color::Black;
				button5->FlatStyle = FlatStyle::Flat;
				button5->FlatAppearance->BorderSize = 0;

				// Grillas
				array<DataGridView^>^ grids = { dataGridEstadisticas, dataGridDetalle };
				for each (DataGridView ^ dgv in grids) {
					dgv->BackgroundColor = System::Drawing::Color::White;
					dgv->BorderStyle = BorderStyle::None;
					dgv->EnableHeadersVisualStyles = false;
					dgv->ColumnHeadersDefaultCellStyle->BackColor = colorVerde;
					dgv->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
					dgv->ColumnHeadersDefaultCellStyle->Font = fuenteBold;
					dgv->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(180, 220, 180);
					dgv->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
					dgv->RowHeadersVisible = false;
					dgv->Dock = DockStyle::Fill;
				}

				// Gráficos (Responsive)
				if (chartTipoAnalisis != nullptr) {
					chartTipoAnalisis->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);
					chartTipoAnalisis->Width = tabPage1->Width - 20;
					chartTipoAnalisis->BackColor = System::Drawing::Color::Transparent;
					if (chartTipoAnalisis->ChartAreas->Count > 0) chartTipoAnalisis->ChartAreas[0]->BackColor = System::Drawing::Color::White;
				}
				if (chartEstadoSalud != nullptr) {
					chartEstadoSalud->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);
					chartEstadoSalud->Width = tabPage1->Width - 20;
					chartEstadoSalud->Height = tabPage1->Height - chartEstadoSalud->Top - 10;
					chartEstadoSalud->BackColor = System::Drawing::Color::Transparent;
					if (chartEstadoSalud->ChartAreas->Count > 0) chartEstadoSalud->ChartAreas[0]->BackColor = System::Drawing::Color::White;
				}

				// Labels
				array<Label^>^ labels = { label1, label2, label3, label4, label5, label6 };
				for each (Label ^ l in labels) l->ForeColor = colorTexto;

				radioMensual->ForeColor = colorTexto;
				radioRango->ForeColor = colorTexto;
			}
			void ConfigurarCharts() {
				// --- GRÁFICO 1: TIPOS DE ANÁLISIS (Barras) ---
				if (chartTipoAnalisis != nullptr) {
					chartTipoAnalisis->ChartAreas->Clear();
					chartTipoAnalisis->Series->Clear();
					chartTipoAnalisis->Legends->Clear();
					chartTipoAnalisis->Titles->Clear();

					// Área de gráfico con fondo limpio
					ChartArea^ areaTipos = gcnew ChartArea("AreaTipos");
					areaTipos->BackColor = System::Drawing::Color::WhiteSmoke; // Fondo gris suave

					// Ejes más legibles
					areaTipos->AxisX->Title = "Tipo de Análisis";
					areaTipos->AxisX->TitleFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
					areaTipos->AxisX->LabelStyle->Font = gcnew System::Drawing::Font("Arial", 8);
					areaTipos->AxisX->Interval = 1; // Mostrar todas las etiquetas

					// Rejilla suave para ver mejor las alturas
					areaTipos->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
					areaTipos->AxisX->MajorGrid->Enabled = false; // Sin rejilla vertical

					chartTipoAnalisis->ChartAreas->Add(areaTipos);

					// Título elegante
					Title^ titulo = gcnew Title("Distribución por Tipo de Análisis");
					titulo->Font = gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold);
					chartTipoAnalisis->Titles->Add(titulo);

					// Paleta de colores bonita (Verde mar)
					chartTipoAnalisis->Palette = ChartColorPalette::SeaGreen;
				}

				// --- GRÁFICO 2: ESTADO DE SALUD (Pastel/Pie) ---
				if (chartEstadoSalud != nullptr) {
					chartEstadoSalud->ChartAreas->Clear();
					chartEstadoSalud->Series->Clear();
					chartEstadoSalud->Legends->Clear();
					chartEstadoSalud->Titles->Clear();

					ChartArea^ areaSalud = gcnew ChartArea("AreaSalud");
					areaSalud->BackColor = System::Drawing::Color::Transparent;
					chartEstadoSalud->ChartAreas->Add(areaSalud);

					// Agregar Leyenda (Cuadrito con colores a la derecha)
					Legend^ leyenda = gcnew Legend("LeyendaSalud");
					leyenda->Docking = Docking::Right; // Poner a la derecha
					leyenda->Alignment = System::Drawing::StringAlignment::Center;
					chartEstadoSalud->Legends->Add(leyenda);

					Title^ titulo = gcnew Title("Estado de Salud General");
					titulo->Font = gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold);
					chartEstadoSalud->Titles->Add(titulo);

					// Paleta de colores vivos (Pastel)
					chartEstadoSalud->Palette = ChartColorPalette::BrightPastel;
				}
			}
			

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void groupBox3_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label6_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
}; // Fin de la clase frmMantReporteDiagnostico

    } // Fin del namespace AgroRobotView