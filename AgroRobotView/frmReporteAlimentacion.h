#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	public ref class frmReporteAlimentacion : public System::Windows::Forms::Form
	{
	public:
		frmReporteAlimentacion(void)
		{
			InitializeComponent();
			// APLICAR ESTILO PROFESIONAL AL INICIAR
			AplicarEstiloProfesional();
		}

	protected:
		~frmReporteAlimentacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnExportar;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnExportar = (gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();

			// chart1
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(28, 80);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(675, 324);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";

			// label1
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(23, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(337, 30);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Reporte de Consumo por Especie";

			// btnExportar
			this->btnExportar->Location = System::Drawing::Point(520, 25);
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(180, 35);
			this->btnExportar->TabIndex = 2;
			this->btnExportar->Text = L"Exportar Datos";
			this->btnExportar->UseVisualStyleBackColor = true;
			this->btnExportar->Click += gcnew System::EventHandler(this, &frmReporteAlimentacion::btnExportar_Click);

			// frmReporteAlimentacion
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 429);
			this->Controls->Add(this->btnExportar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Name = L"frmReporteAlimentacion";
			this->Text = L"Reporte de Alimentación";
			this->Load += gcnew System::EventHandler(this, &frmReporteAlimentacion::frmReporteAlimentacion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// =========================================================
		// APLICAR ESTILO Y ESCALADO (AQUÍ ESTÁ LA LÓGICA)
		// =========================================================
		void AplicarEstiloProfesional() {
			// ===================================================================================
			// A) DEFINICIÓN DE LA PALETA "AGROROBOT MENTA/BOSQUE"
			// ===================================================================================
			System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248);   // Menta Pálido
			System::Drawing::Color colorBoton = System::Drawing::Color::FromArgb(46, 143, 77);     // Verde Bosque
			System::Drawing::Color colorTextoMain = System::Drawing::Color::FromArgb(22, 53, 45);   // Verde Petróleo
			System::Drawing::Color colorTextoSec = System::Drawing::Color::FromArgb(64, 106, 90);    // Verde Azulado
			System::Drawing::Color colorGridLine = System::Drawing::Color::FromArgb(183, 220, 200);   // Verde Agua

			// Fuentes estandarizadas
			System::Drawing::Font^ fuenteTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 17, FontStyle::Bold);
			System::Drawing::Font^ fuenteBoton = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Bold);
			System::Drawing::Font^ fuenteChartAxis = gcnew System::Drawing::Font("Segoe UI Semibold", 9);
			System::Drawing::Font^ fuenteLegend = gcnew System::Drawing::Font("Microsoft Sans Serif", 9);

			// ===================================================================================
			// B) CONFIGURACIÓN VENTANA PADRE
			// ===================================================================================
			this->BackColor = colorFondo;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->AutoSize = false;
			this->Dock = DockStyle::Fill;

			// ===================================================================================
			// C) CONTROLES FIJOS (Título y Botón)
			// ===================================================================================

			// 1. Título (Label1)
			this->label1->ForeColor = colorTextoMain;
			this->label1->Font = fuenteTitulo;
			this->label1->Top = 20; // Espaciado superior estándar
			this->label1->Left = 28;
			this->label1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);

			// 2. Botón Exportar
			this->btnExportar->Size = System::Drawing::Size(160, 40); // Tamaño consistente con otras pantallas
			this->btnExportar->Top = 20; // Alineado con el título
			this->btnExportar->Left = this->ClientSize.Width - this->btnExportar->Width - 30;
			this->btnExportar->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right);

			this->btnExportar->BackColor = colorBoton; // Verde Bosque exacto
			this->btnExportar->ForeColor = System::Drawing::Color::White;
			this->btnExportar->FlatStyle = FlatStyle::Flat;
			this->btnExportar->FlatAppearance->BorderSize = 0;
			this->btnExportar->Font = fuenteBoton;
			this->btnExportar->Cursor = Cursors::Hand;

			// ===================================================================================
			// D) ESCALADO Y ESTILO DEL GRÁFICO
			// ===================================================================================
			int margen = 30;
			this->chart1->Top = 80; // Espacio suficiente bajo el título
			this->chart1->Left = margen;

			// 1. Calculamos tamaño inicial
			this->chart1->Width = this->ClientSize.Width - (margen * 2);
			this->chart1->Height = this->ClientSize.Height - this->chart1->Top - margen;

			// 2. Anclajes (Logic original preservada)
			this->chart1->Anchor = static_cast<AnchorStyles>(
				AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			// 3. Estilo Visual del Chart
			// El fondo contenedor se funde con la ventana
			this->chart1->BackColor = colorFondo;
			this->chart1->BorderlineColor = System::Drawing::Color::Empty;

			// Configuración del Área del Gráfico (Plot Area)
			if (this->chart1->ChartAreas->Count > 0) {
				System::Windows::Forms::DataVisualization::Charting::ChartArea^ area = this->chart1->ChartAreas[0];

				// Fondo blanco para resaltar los datos (Efecto papel)
				area->BackColor = System::Drawing::Color::White;

				// Bordes suaves del área
				area->BorderColor = colorGridLine;
				area->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;

				// Estilo de Ejes
				area->AxisX->LabelStyle->ForeColor = colorTextoSec;
				area->AxisX->LabelStyle->Font = fuenteChartAxis;
				area->AxisX->LineColor = colorTextoSec;

				area->AxisY->LabelStyle->ForeColor = colorTextoSec;
				area->AxisY->LabelStyle->Font = fuenteChartAxis;
				area->AxisY->LineColor = colorTextoSec;

				// Estilo de la Grilla (Grid Lines) - Punteada y color suave
				area->AxisX->MajorGrid->LineColor = colorGridLine;
				area->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;

				area->AxisY->MajorGrid->LineColor = colorGridLine;
				area->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			}

			// Configuración de la Leyenda
			if (this->chart1->Legends->Count > 0) {
				this->chart1->Legends[0]->BackColor = colorFondo; // Se funde con el fondo
				this->chart1->Legends[0]->ForeColor = colorTextoMain;
				this->chart1->Legends[0]->Font = fuenteLegend;
			}
		}

	private: System::Void frmReporteAlimentacion_Load(System::Object^ sender, System::EventArgs^ e) {
		// 1. RECOLECCIÓN DE DATOS
		Dictionary<String^, int>^ contador = gcnew Dictionary<String^, int>();

		if (File::Exists("animales.txt")) {
			array<String^>^ lineas = File::ReadAllLines("animales.txt");
			for each (String ^ linea in lineas) {
				if (linea->Trim() == "") continue;
				array<String^>^ partes = linea->Split(';');
				if (partes->Length > 7) {
					String^ especie = partes[1];
					int veces = 0;
					try { veces = Convert::ToInt32(partes[7]); }
					catch (...) { veces = 0; }
					if (contador->ContainsKey(especie)) contador[especie] += veces;
					else contador->Add(especie, veces);
				}
			}
		}

		// 2. LIMPIEZA Y CONFIGURACIÓN BÁSICA
		chart1->Series["Series1"]->Points->Clear();
		chart1->Series["Series1"]->ChartType = SeriesChartType::Pie;

		if (chart1->ChartAreas->Count > 0) {
			chart1->ChartAreas[0]->Area3DStyle->Enable3D = false;

			// Margen interno para las líneas conectoras
			chart1->ChartAreas[0]->InnerPlotPosition->Auto = false;
			chart1->ChartAreas[0]->InnerPlotPosition->X = 12;
			chart1->ChartAreas[0]->InnerPlotPosition->Y = 12;
			chart1->ChartAreas[0]->InnerPlotPosition->Height = 76;
			chart1->ChartAreas[0]->InnerPlotPosition->Width = 76;
		}

		// 3. CONFIGURACIÓN DE TEXTOS
		chart1->Series["Series1"]->Font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);

		// Mostrar solo NOMBRE en el gráfico
		chart1->Series["Series1"]->Label = "#VALX";

		// Mostrar NOMBRE y PORCENTAJE en la leyenda
		chart1->Series["Series1"]->LegendText = "#VALX: #PERCENT";

		// Estilo de Líneas Conectoras
		chart1->Series["Series1"]->SetCustomProperty("PieLabelStyle", "Outside");
		chart1->Series["Series1"]->SetCustomProperty("PieLineColor", "Black");
		chart1->Series["Series1"]->SmartLabelStyle->Enabled = true;

		// Configurar Leyenda
		if (chart1->Legends->Count > 0) {
			chart1->Legends[0]->Font = gcnew System::Drawing::Font("Segoe UI", 11, FontStyle::Regular);
			chart1->Legends[0]->Docking = Docking::Right;
			chart1->Legends[0]->Alignment = System::Drawing::StringAlignment::Center;
		}

		// 4. PALETA OTOÑAL / TIERRA (Elegante y con contraste)
		array<System::Drawing::Color>^ paletaColores = {
			System::Drawing::Color::FromArgb(204, 88, 67),   // Rojo Ladrillo (Cálido)
			System::Drawing::Color::FromArgb(242, 186, 73),  // Amarillo Mostaza (Luminoso)
			System::Drawing::Color::FromArgb(106, 142, 79),  // Verde Oliva (Natural)
			System::Drawing::Color::FromArgb(70, 130, 180),  // Azul Acero (Contraste Frío)
			System::Drawing::Color::FromArgb(211, 84, 0),    // Calabaza / Naranja Fuerte
			System::Drawing::Color::FromArgb(139, 69, 19),   // Marrón Chocolate (Tierra)
			System::Drawing::Color::FromArgb(142, 68, 173),  // Púrpura Ciruela (Profundo)
			System::Drawing::Color::FromArgb(189, 195, 199)  // Gris Plata (Neutro)
		};

		int colorIndex = 0;

		// 5. LLENADO DE DATOS
		for each (KeyValuePair<String^, int> kvp in contador) {
			int idx = chart1->Series["Series1"]->Points->AddXY(kvp.Key, kvp.Value);

			// Asignar color otoñal cíclicamente
			chart1->Series["Series1"]->Points[idx]->Color = paletaColores[colorIndex % paletaColores->Length];
			colorIndex++;
		}
	}

		   // Lógica de exportación (igual que antes)
	private: System::Void btnExportar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Reporte de Texto|*.txt";
			saveDialog->FileName = "Reporte_Alimentacion_" + DateTime::Now.ToString("yyyyMMdd_HHmmss") + ".txt";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				StreamWriter^ writer = gcnew StreamWriter(saveDialog->FileName, false, System::Text::Encoding::UTF8);
				writer->WriteLine("AGROROBOT - REPORTE DE CONSUMO");
				writer->WriteLine("Fecha: " + DateTime::Now.ToString("g"));
				writer->WriteLine("------------------------------");

				Dictionary<String^, int>^ datos = gcnew Dictionary<String^, int>();
				if (File::Exists("animales.txt")) {
					array<String^>^ lineas = File::ReadAllLines("animales.txt");
					for each (String ^ linea in lineas) {
						if (linea->Trim() == "") continue;
						array<String^>^ p = linea->Split(';');
						if (p->Length > 7) {
							String^ sp = p[1];
							int v = 0; try { v = Convert::ToInt32(p[7]); }
							catch (...) { v = 0; }
							if (datos->ContainsKey(sp)) datos[sp] += v; else datos->Add(sp, v);
						}
					}
				}
				for each (KeyValuePair<String^, int> item in datos) {
					writer->WriteLine(item.Key + ": " + item.Value);
				}
				writer->Close();
				MessageBox::Show("Reporte exportado con éxito.");
			}
		}
		catch (Exception^ ex) { MessageBox::Show("Error: " + ex->Message); }
	}
	};
}