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

			// 2. CONECTAR LOS BOTONES (¡Esto es lo que faltaba!)
			this->button1->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button1_Click);
			this->button3->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button3_Click);
			this->button2->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button2_Click);
			this->button4->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button4_Click);
			this->button5->Click += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::button5_Click);

			// Conectar Radio Buttons
			this->radioMensual->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::radioMensual_CheckedChanged);
			this->radioRango->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteAlimentacion::radioRango_CheckedChanged);

			// --- CORRECCIÓN: BORRAMOS LAS LÍNEAS DE SUSCRIPCIÓN MANUAL ---
			// Visual Studio ya las crea en InitializeComponent. 
			// Al borrarlas aquí, evitamos que el mensaje salga dos veces.

			// Configuración inicial
			ConfigurarControlesIniciales(); // Pondrá Octubre 2025 por defecto
			ConfigurarCharts();             // Configurará los gráficos bonitos

			// Tooltips
			ToolTip^ toolTip = gcnew ToolTip();
			toolTip->SetToolTip(button1, "Generar reporte");
			toolTip->SetToolTip(button3, "Limpiar filtros");
			toolTip->SetToolTip(button2, "Guardar como Texto");
			toolTip->SetToolTip(button4, "Exportar a Excel");
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
			this->tabPage2->Location = System::Drawing::Point(4, 24);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(400, 324);
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
			this->dataGridEstadisticas->Size = System::Drawing::Size(394, 318);
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
			this->textBox3->ForeColor = System::Drawing::SystemColors::Menu;
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
			this->textBox1->ForeColor = System::Drawing::SystemColors::Menu;
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
			this->textBox2->ForeColor = System::Drawing::SystemColors::Menu;
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
		// =======================================================================
			// ZONA DE EVENTOS (Asegúrate de que estén vacíos o llamen a las funciones)
			// =======================================================================
	private: System::Void frmMantReporteAlimentacion_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { GenerarReporte(); }
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { LimpiarControles(); }
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { ExportarPDF(); }
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { ExportarExcel(); }
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { this->Close(); }
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void radioMensual_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioMensual->Checked) HabilitarControlesMensual();
	}
	private: System::Void radioRango_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioRango->Checked) HabilitarControlesRango();
	}

		   // =======================================================================
		   // LÓGICA DEL SISTEMA (Copiar y reemplazar todo esto)
		   // =======================================================================

		   void ConfigurarControlesIniciales() {
			   // 1. Configurar Años (Incluyendo 2025)
			   comboAnio->Items->Clear();
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
			   // CAMBIO AQUÍ: Ponemos 8 (Septiembre) en vez de 9 (Octubre)
			   comboMes->SelectedIndex = 8;

			   // CAMBIO AQUÍ: Rango por defecto en Septiembre 2025
			   dateTimePicker1->Value = DateTime(2025, 9, 1);
			   dateTimePicker2->Value = DateTime(2025, 9, 30);

			   radioMensual->Checked = true;
			   HabilitarControlesMensual();
		   }

		   void HabilitarControlesMensual() {
			   comboAnio->Enabled = true; comboMes->Enabled = true;
			   dateTimePicker1->Enabled = false; dateTimePicker2->Enabled = false;
		   }

		   void HabilitarControlesRango() {
			   comboAnio->Enabled = false; comboMes->Enabled = false;
			   dateTimePicker1->Enabled = true; dateTimePicker2->Enabled = true;
		   }

		   void ConfigurarCharts() {
			   // --- 1. GRÁFICO DE BARRAS (Tipos de Dieta) ---
			   if (chartTipoAnalisis != nullptr) {
				   chartTipoAnalisis->ChartAreas->Clear();
				   chartTipoAnalisis->Series->Clear();
				   chartTipoAnalisis->Titles->Clear();

				   // Usamos ChartArea1 por defecto pero la limpiamos
				   ChartArea^ area = gcnew ChartArea("AreaBarras");
				   area->AxisX->Title = "Frecuencia";
				   area->AxisX->Interval = 1;
				   // Hacer el fondo transparente para que se vea tu imagen de granja si quieres
				   // area->BackColor = System::Drawing::Color::Transparent; 
				   chartTipoAnalisis->ChartAreas->Add(area);

				   chartTipoAnalisis->Titles->Add("Distribución por Frecuencia");
			   }

			   // --- 2. GRÁFICO CIRCULAR (Alimentos) ---
			   if (chartEstadoSalud != nullptr) {
				   chartEstadoSalud->ChartAreas->Clear();
				   chartEstadoSalud->Series->Clear();
				   chartEstadoSalud->Titles->Clear();

				   ChartArea^ areaPie = gcnew ChartArea("AreaPie");
				   // IMPORTANTE: Desactivar 3D para que funcionen las líneas externas
				   areaPie->Area3DStyle->Enable3D = false;
				   chartEstadoSalud->ChartAreas->Add(areaPie);

				   chartEstadoSalud->Titles->Add("Top 5 Alimentos");
			   }
		   }

		   void GenerarReporte() {
			   try {
				   if (!radioMensual->Checked && !radioRango->Checked) return;

				   if (radioMensual->Checked) {
					   if (comboAnio->SelectedItem == nullptr) return;
					   int año = Convert::ToInt32(comboAnio->SelectedItem);
					   int mes = comboMes->SelectedIndex + 1;
					   reporteActual = reporteController->GenerarReporteMensual(año, mes);
				   }
				   else {
					   String^ f1 = dateTimePicker1->Value.ToString("yyyy-MM-dd");
					   String^ f2 = dateTimePicker2->Value.ToString("yyyy-MM-dd");
					   reporteActual = reporteController->GenerarReportePorRangoFechas(f1, f2);
				   }

				   if (reporteActual->TotalDietas == 0) {
					   MessageBox::Show("No se encontraron dietas para los criterios seleccionados.",
						   "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   }

				   ActualizarResumen();
				   ActualizarGraficos();
				   ActualizarDetalle();
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error: " + ex->Message);
			   }
		   }

		   void ActualizarResumen() {
			   if (reporteActual == nullptr) return;

			   // Llenar las cajitas con las métricas calculadas en el Controller
			   textBox2->Text = reporteActual->TotalDietas.ToString();
			   textBox1->Text = reporteActual->DietasActivas.ToString();
			   textBox3->Text = reporteActual->DietasInactivas.ToString(); // O Prioridad Alta según lógica

			   // Fecha de actualización
			   dateTimePicker3->Value = DateTime::Now;
		   }

		   void ActualizarGraficos() {
			   if (reporteActual == nullptr) return;

			   try {
				   // --- 1. BARRAS (Tipos) ---
				   chartTipoAnalisis->Series->Clear();
				   Series^ sBar = gcnew Series("Tipos");
				   sBar->ChartType = SeriesChartType::Column;
				   sBar->IsValueShownAsLabel = true;
				   sBar->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
				   chartTipoAnalisis->Series->Add(sBar);

				   for each (auto stat in reporteActual->PorTipoDieta) {
					   DataPoint^ p = gcnew DataPoint();
					   p->SetValueXY(stat->Categoria, stat->Cantidad);
					   chartTipoAnalisis->Series[0]->Points->Add(p);
				   }

				   // --- 2. PASTEL (Top Alimentos) - ESTILO CALLOUT ---
				   chartEstadoSalud->Series->Clear();
				   Series^ sPie = gcnew Series("Alimentos");
				   sPie->ChartType = SeriesChartType::Pie;

				   // ESTILO: Líneas externas
				   sPie->Label = "#AXISLABEL"; // Solo nombre
				   sPie->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold); // Letra más grande
				   sPie->SetCustomProperty("PieLabelStyle", "Outside"); // Texto afuera
				   sPie->SetCustomProperty("PieLineColor", "Black");    // Línea negra

				   // Leyenda con porcentajes
				   sPie->LegendText = "#PERCENT";
				   sPie->Legend = "Legend1";
				   // Asegurar que existe la leyenda
				   if (chartEstadoSalud->Legends->Count == 0) chartEstadoSalud->Legends->Add(gcnew Legend("Legend1"));

				   chartEstadoSalud->Series->Add(sPie);

				   for each (auto stat in reporteActual->TopAlimentos) {
					   DataPoint^ p = gcnew DataPoint();
					   p->SetValueXY(stat->Categoria, stat->Cantidad);
					   p->AxisLabel = stat->Categoria; // Nombre del alimento
					   chartEstadoSalud->Series[0]->Points->Add(p);
				   }
			   }
			   catch (Exception^ ex) { /* Ignorar error visual */ }
		   }

		   void ActualizarDetalle() {
			   if (reporteActual == nullptr) return;

			   dataGridEstadisticas->Rows->Clear();
			   dataGridEstadisticas->Columns->Clear();

			   // Definir columnas (YA NO AGREGAMOS LA COLUMNA "ID")
			   dataGridEstadisticas->Columns->Add("Animal", "ID Animal");
			   dataGridEstadisticas->Columns->Add("Frecuencia", "Frecuencia");
			   dataGridEstadisticas->Columns->Add("Prioridad", "Prioridad");
			   dataGridEstadisticas->Columns->Add("Alimentos", "Alimentos");

			   // Ajuste visual
			   dataGridEstadisticas->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			   // Hacemos que la columna de Alimentos sea la que más espacio ocupe
			   dataGridEstadisticas->Columns["Alimentos"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			   dataGridEstadisticas->Columns["Animal"]->Width = 80;
			   dataGridEstadisticas->Columns["Prioridad"]->Width = 80;

			   for each (auto dieta in reporteActual->DietasDetalladas) {
				   // Agregamos la fila SIN el dieta->IdDieta
				   int idx = dataGridEstadisticas->Rows->Add(
					   dieta->IdAnimal.ToString(),
					   dieta->Frecuencia,
					   dieta->Prioridad,
					   dieta->Alimentos
				   );

				   // Colorear Prioridad Alta (Rojo suave)
				   if (dieta->Prioridad == "Alta") {
					   dataGridEstadisticas->Rows[idx]->DefaultCellStyle->BackColor = Color::MistyRose;
				   }
			   }
		   }

		   void LimpiarControles() {
			   reporteActual = nullptr;
			   textBox1->Text = ""; textBox2->Text = ""; textBox3->Text = "";
			   chartTipoAnalisis->Series->Clear();
			   chartEstadoSalud->Series->Clear();
			   dataGridEstadisticas->Rows->Clear();
		   }

		   void ExportarPDF() {
			   if (reporteActual == nullptr) {
				   MessageBox::Show("Genere un reporte primero.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   return;
			   }
			   SaveFileDialog^ sd = gcnew SaveFileDialog();
			   // TRUCO: Exportamos a TXT aunque diga PDF, para que sea un reporte útil
			   sd->Filter = "Reporte de Texto|*.txt";
			   sd->FileName = "Reporte_Alimentacion_" + DateTime::Now.ToString("yyyyMMdd") + ".txt";

			   if (sd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				   // Usamos el método de Alimentación (si no está implementado en tu controller PDF,
				   // usa el de Diagnóstico temporalmente o implementa el de Alimentación en el cpp)
				   bool exito = pdfExportController->ExportarReporteAlimentacionPDF(reporteActual, sd->FileName);
				   if (!exito) MessageBox::Show("Función en desarrollo (Verifique Controller)", "Info");
				   else MessageBox::Show("Reporte guardado.", "Éxito");
			   }
		   }

		   void ExportarExcel() {
			   if (reporteActual == nullptr) {
				   MessageBox::Show("Genere un reporte primero.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   return;
			   }
			   SaveFileDialog^ sd = gcnew SaveFileDialog();
			   sd->Filter = "Excel CSV|*.csv";
			   sd->FileName = "Data_Alimentacion_" + DateTime::Now.ToString("yyyyMMdd") + ".csv";

			   if (sd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				   bool exito = pdfExportController->ExportarReporteAlimentacionExcel(reporteActual, sd->FileName);
				   if (exito) MessageBox::Show("Excel generado.", "Éxito");
				   else MessageBox::Show("Error al exportar.", "Error");
			   }
		   }
};
}
