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
	/// Resumen de frmMantReporteAlimentacion
	/// </summary>
	public ref class frmMantReporteAlimentacion : public System::Windows::Forms::Form
	{
	public:
		frmMantReporteAlimentacion(void)
		{
			InitializeComponent();
			// Inicializar controladores
			this->reporteController = gcnew ReporteAlimentacionController();
			this->pdfExportController = gcnew PdfExportServiceController();
			this->reporteActual = nullptr;

			// En el constructor, después de InitializeComponent();
			this->button1->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button1_Click);
			this->button3->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button3_Click);
			this->button2->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button2_Click);
			this->button4->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button4_Click);
			this->radioMensual->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::radioMensual_CheckedChanged);
			this->radioRango->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::radioRango_CheckedChanged);

			// Configuración inicial
			ConfigurarControlesIniciales();
			ConfigurarCharts();
			ToolTip^ toolTip = gcnew ToolTip();
			toolTip->SetToolTip(button1, "Generar reporte con los criterios seleccionados");
			toolTip->SetToolTip(button3, "Limpiar todos los filtros y resultados");
			toolTip->SetToolTip(button2, "Exportar reporte a formato PDF");
			toolTip->SetToolTip(button4, "Exportar reporte a formato Excel");
			toolTip->SetToolTip(comboAnio, "Seleccionar año para reporte mensual");
			toolTip->SetToolTip(comboMes, "Seleccionar mes para reporte mensual");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantReporteAlimentacion()
		{
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

	protected:

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartTipoAnalisis;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartEstadoSalud;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataGridView^ dataGridEstadisticas;

		
	
	private: ReporteAlimentacionController^ reporteController;
	private: PdfExportServiceController^ pdfExportController;
	private: ReporteAlimentacionResult^ reporteActual;





	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioMensual;
	private: System::Windows::Forms::RadioButton^ radioRango;
	private: System::Windows::Forms::ComboBox^ comboAnio;
	private: System::Windows::Forms::ComboBox^ comboMes;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker3;
	private: System::Windows::Forms::Button^ button5;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMantReporteAlimentacion::typeid));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->chartTipoAnalisis = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartEstadoSalud = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridEstadisticas = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioMensual = (gcnew System::Windows::Forms::RadioButton());
			this->radioRango = (gcnew System::Windows::Forms::RadioButton());
			this->comboAnio = (gcnew System::Windows::Forms::ComboBox());
			this->comboMes = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTipoAnalisis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstadoSalud))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEstadisticas))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(350, 153);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Excel";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(252, 153);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"PDF";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(36, 232);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(408, 352);
			this->tabControl1->TabIndex = 9;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->chartTipoAnalisis);
			this->tabPage1->Controls->Add(this->chartEstadoSalud);
			this->tabPage1->Location = System::Drawing::Point(4, 24);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(400, 324);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Gráficos de Alimentación";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// chartTipoAnalisis
			// 
			this->chartTipoAnalisis->Location = System::Drawing::Point(10, 10);
			this->chartTipoAnalisis->Name = L"chartTipoAnalisis";
			this->chartTipoAnalisis->Size = System::Drawing::Size(380, 140);
			this->chartTipoAnalisis->TabIndex = 0;
			this->chartTipoAnalisis->Text = L"Tipos de Dieta";
			// 
			// chartEstadoSalud
			// 
			this->chartEstadoSalud->Location = System::Drawing::Point(18, 155);
			this->chartEstadoSalud->Name = L"chartEstadoSalud";
			this->chartEstadoSalud->Size = System::Drawing::Size(380, 130);
			this->chartEstadoSalud->TabIndex = 1;
			this->chartEstadoSalud->Text = L"Alimentos Más Usados";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridEstadisticas);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(400, 326);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Detalle de Dietas";
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
			this->dataGridEstadisticas->Size = System::Drawing::Size(394, 320);
			this->dataGridEstadisticas->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->groupBox1->Controls->Add(this->radioMensual);
			this->groupBox1->Controls->Add(this->radioRango);
			this->groupBox1->Controls->Add(this->comboAnio);
			this->groupBox1->Controls->Add(this->comboMes);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->dateTimePicker2);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->groupBox1->Location = System::Drawing::Point(36, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(408, 113);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de búsqueda";
			// 
			// radioMensual
			// 
			this->radioMensual->AutoSize = true;
			this->radioMensual->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioMensual->Location = System::Drawing::Point(24, 72);
			this->radioMensual->Name = L"radioMensual";
			this->radioMensual->Size = System::Drawing::Size(71, 19);
			this->radioMensual->TabIndex = 14;
			this->radioMensual->TabStop = true;
			this->radioMensual->Text = L"Mensual";
			this->radioMensual->UseVisualStyleBackColor = true;
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
			// 
			// comboAnio
			// 
			this->comboAnio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->comboAnio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboAnio->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboAnio->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->comboAnio->FormattingEnabled = true;
			this->comboAnio->Location = System::Drawing::Point(100, 70);
			this->comboAnio->Name = L"comboAnio";
			this->comboAnio->Size = System::Drawing::Size(70, 23);
			this->comboAnio->TabIndex = 16;
			// 
			// comboMes
			// 
			this->comboMes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->comboMes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboMes->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboMes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->comboMes->FormattingEnabled = true;
			this->comboMes->Location = System::Drawing::Point(180, 70);
			this->comboMes->Name = L"comboMes";
			this->comboMes->Size = System::Drawing::Size(100, 23);
			this->comboMes->TabIndex = 17;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(227, 36);
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
			this->dateTimePicker2->Location = System::Drawing::Point(257, 33);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(121, 22);
			this->dateTimePicker2->TabIndex = 6;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(87, 33);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(121, 22);
			this->dateTimePicker1->TabIndex = 2;
			this->dateTimePicker1->Value = System::DateTime(2022, 1, 1, 0, 0, 0, 0);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(152, 153);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 23);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Limpiar";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(53, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->groupBox2->Controls->Add(this->dateTimePicker3);
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
			this->groupBox2->Location = System::Drawing::Point(32, 609);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(408, 113);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Métricas Principales";
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker3->Location = System::Drawing::Point(295, 73);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(87, 22);
			this->dateTimePicker3->TabIndex = 10;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Location = System::Drawing::Point(198, 73);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(74, 22);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(104, 73);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(70, 22);
			this->textBox1->TabIndex = 8;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(292, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Fecha Dietas";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(195, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 34);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Dietas\r\nInactivas";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(101, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 34);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Dietas\r\nActivas";
			this->label1->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::label1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Location = System::Drawing::Point(26, 73);
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
			this->label6->Location = System::Drawing::Point(23, 31);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 34);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Prioridad\r\nAlta";
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->button5->Location = System::Drawing::Point(350, 186);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 23);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button5_Click);
			// 
			// frmMantReporteAlimentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(473, 741);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"frmMantReporteAlimentacion";
			this->Text = L"Reporte de Plan Alimenticio - Dietas";
			this->Load += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::frmMantReporteAlimentacion_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTipoAnalisis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstadoSalud))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEstadisticas))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void frmMantReporteAlimentacion_Load(System::Object^ sender, System::EventArgs^ e) {
}

private:
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

	System::Void radioMensual_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		HabilitarControlesMensual();
	}

	System::Void radioRango_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		HabilitarControlesRango();
	}

private:
	void ConfigurarControlesIniciales() {
		// Configurar años (últimos 5 años)
		int añoActual = DateTime::Now.Year;
		for (int i = añoActual; i >= añoActual - 5; i--) {
			comboAnio->Items->Add(i.ToString());
		}
		comboAnio->SelectedIndex = 0;

		// Configurar meses
		array<String^>^ meses = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
								"Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
		comboMes->Items->AddRange(meses);
		comboMes->SelectedIndex = DateTime::Now.Month - 1;

		// Configurar fechas por defecto
		dateTimePicker1->Value = DateTime::Today.AddMonths(-1);
		dateTimePicker2->Value = DateTime::Today;

		HabilitarControlesMensual();
	}

	void ConfigurarCharts() {
		// Configurar chart de tipos de dieta
		if (chartTipoAnalisis != nullptr) {
			chartTipoAnalisis->ChartAreas->Clear();
			chartTipoAnalisis->Series->Clear();
			chartTipoAnalisis->Titles->Clear();

			chartTipoAnalisis->ChartAreas->Add("ChartArea1");
			chartTipoAnalisis->Titles->Add("Distribución por Tipo de Dieta");
		}

		// Configurar chart de alimentos
		if (chartEstadoSalud != nullptr) {
			chartEstadoSalud->ChartAreas->Clear();
			chartEstadoSalud->Series->Clear();
			chartEstadoSalud->Titles->Clear();

			chartEstadoSalud->ChartAreas->Add("ChartArea1");
			chartEstadoSalud->Titles->Add("Top 5 Alimentos Más Usados");
		}
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

private:
	void GenerarReporte() {
		try {
			// Validar que se haya seleccionado un criterio
			if (!radioMensual->Checked && !radioRango->Checked) {
				MessageBox::Show("Por favor seleccione un criterio de búsqueda (Mensual o Rango)",
					"Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			if (radioMensual->Checked) {
				// Validar que se haya seleccionado año y mes
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

			if (reporteActual->TotalDietas == 0) {
				MessageBox::Show("No se encontraron dietas para los criterios seleccionados",
					"Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			ActualizarResumen();
			ActualizarGraficos();
			ActualizarDetalle();

		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al generar reporte: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void ActualizarResumen() {
		if (reporteActual == nullptr) return;

		textBox2->Text = reporteActual->TotalDietas.ToString();
		textBox1->Text = reporteActual->DietasActivas.ToString();
		textBox3->Text = reporteActual->DietasInactivas.ToString();

		// Para la prioridad alta, por ahora usamos un valor fijo
		dateTimePicker3->Value = DateTime::Today;
	}

	void ActualizarGraficos() {
		if (reporteActual == nullptr) return;

		try {
			// Limpiar gráficos anteriores
			chartTipoAnalisis->Series->Clear();
			chartEstadoSalud->Series->Clear();

			// Configurar chart de tipos de dieta
			if (reporteActual->PorTipoDieta->Count > 0) {
				Series^ seriesTipos = gcnew Series("TiposDieta");
				seriesTipos->ChartType = SeriesChartType::Column;
				seriesTipos->IsValueShownAsLabel = true;
				seriesTipos->LabelFormat = "{0}"; // Mostrar valores enteros
				chartTipoAnalisis->Series->Add(seriesTipos);

				for each (auto stat in reporteActual->PorTipoDieta) {
					DataPoint^ point = gcnew DataPoint();
					point->SetValueXY(stat->Categoria, stat->Cantidad);
					point->Label = stat->Cantidad.ToString();
					chartTipoAnalisis->Series["TiposDieta"]->Points->Add(point);
				}
			}

			// Configurar chart de alimentos
			if (reporteActual->TopAlimentos->Count > 0) {
				Series^ seriesAlimentos = gcnew Series("Alimentos");
				seriesAlimentos->ChartType = SeriesChartType::Pie;
				seriesAlimentos->IsValueShownAsLabel = true;
				seriesAlimentos->LabelFormat = "#PERCENT{P1}"; // Mostrar porcentajes
				chartEstadoSalud->Series->Add(seriesAlimentos);

				for each (auto stat in reporteActual->TopAlimentos) {
					DataPoint^ point = gcnew DataPoint();
					point->SetValueXY(stat->Categoria, stat->Cantidad);
					point->LegendText = stat->Categoria;
					chartEstadoSalud->Series["Alimentos"]->Points->Add(point);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al actualizar gráficos: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void ActualizarDetalle() {
		if (reporteActual == nullptr) return;

		try {
			dataGridEstadisticas->Rows->Clear();
			dataGridEstadisticas->Columns->Clear();

			// Agregar columnas con mejor configuración
			dataGridEstadisticas->Columns->Add("IdDieta", "ID Dieta");
			dataGridEstadisticas->Columns->Add("IdAnimal", "ID Animal");
			dataGridEstadisticas->Columns->Add("Alimentos", "Alimentos");
			dataGridEstadisticas->Columns->Add("Frecuencia", "Frecuencia");
			dataGridEstadisticas->Columns->Add("Prioridad", "Prioridad");

			// Configurar columnas
			dataGridEstadisticas->Columns["IdDieta"]->Width = 70;
			dataGridEstadisticas->Columns["IdAnimal"]->Width = 70;
			dataGridEstadisticas->Columns["Prioridad"]->Width = 80;

			// Agregar datos
			for each (auto dieta in reporteActual->DietasDetalladas) {
				int rowIndex = dataGridEstadisticas->Rows->Add(
					dieta->IdDieta.ToString(),
					dieta->IdAnimal.ToString(),
					dieta->Alimentos,
					dieta->Frecuencia,
					dieta->Prioridad
				);

				// Colorear filas según prioridad
				if (dieta->Prioridad == "Alta") {
					dataGridEstadisticas->Rows[rowIndex]->DefaultCellStyle->BackColor = Color::LightPink;
				}
				else if (dieta->Prioridad == "Media") {
					dataGridEstadisticas->Rows[rowIndex]->DefaultCellStyle->BackColor = Color::LightYellow;
				}
			}

			// Configurar para que ocupe todo el espacio
			dataGridEstadisticas->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al actualizar detalle: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void LimpiarControles() {
		textBox2->Text = "";
		textBox1->Text = "";
		textBox3->Text = "";
		dateTimePicker3->Value = DateTime::Today;

		// Limpiar gráficos
		if (chartTipoAnalisis != nullptr) chartTipoAnalisis->Series->Clear();
		if (chartEstadoSalud != nullptr) chartEstadoSalud->Series->Clear();

		// Limpiar grid
		dataGridEstadisticas->Rows->Clear();
		dataGridEstadisticas->Columns->Clear();

		reporteActual = nullptr;
	}

	void ExportarPDF() {
		if (reporteActual == nullptr) {
			MessageBox::Show("No hay datos para exportar. Genere un reporte primero.",
				"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivos PDF|*.pdf";
			saveDialog->Title = "Guardar reporte como PDF";
			saveDialog->FileName = "Reporte_Alimentacion_" + DateTime::Now.ToString("yyyyMMdd_HHmm") + ".pdf";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				bool exito = pdfExportController->ExportarReporteAlimentacionPDF(reporteActual, saveDialog->FileName);
				if (exito) {
					MessageBox::Show("Reporte exportado exitosamente a PDF.", "Éxito",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Error al exportar el reporte a PDF.", "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error en exportación PDF: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void ExportarExcel() {
		if (reporteActual == nullptr) {
			MessageBox::Show("No hay datos para exportar. Genere un reporte primero.",
				"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivos CSV|*.csv";
			saveDialog->Title = "Guardar reporte como Excel";
			saveDialog->FileName = "Reporte_Alimentacion_" + DateTime::Now.ToString("yyyyMMdd_HHmm") + ".csv";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				bool exito = pdfExportController->ExportarReporteAlimentacionExcel(reporteActual, saveDialog->FileName);
				if (exito) {
					MessageBox::Show("Reporte exportado exitosamente a Excel.", "Éxito",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Error al exportar el reporte a Excel.", "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error en exportación Excel: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
