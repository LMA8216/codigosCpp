package com.example.streetsafety

//import android.nfc.Tag
import android.os.Bundle
import com.google.android.material.floatingactionbutton.FloatingActionButton
import androidx.appcompat.app.AppCompatActivity
import android.view.Menu
import android.view.MenuItem
import android.widget.EditText
import android.widget.Toast
import android.widget.Toast.LENGTH_LONG
import com.google.firebase.firestore.FirebaseFirestore

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // instancia objeto do firestore
        val db = FirebaseFirestore.getInstance()

        // pega dados digitados
        var nomeDigitado: EditText = findViewById(R.id.nome_editText)
        var profissaoDigitado: EditText = findViewById(R.id.profissao_editText)
        var coordenadaDigitada: EditText = findViewById(R.id.coordenada_editText)


        // clique do botão de envio
        findViewById<FloatingActionButton>(R.id.botao_envia_dados).setOnClickListener {
            // garante que nenhum capo esteja vazio
            if ((nomeDigitado.text.toString() == "") || (profissaoDigitado.text.toString() == "") || (coordenadaDigitada.text.toString() == "")) {
                Toast.makeText(this, "Digite todos os campos", LENGTH_LONG).show()
            }
            else {
                // instancia a classe com os dados
                val u = usuario(
                    nome = nomeDigitado.text.toString(),
                    profissao = profissaoDigitado.text.toString(),
                    coordenada = coordenadaDigitada.text.toString()
                )
                // envia os dados para o firebase
                db.collection("Users").add(
                    hashMapOf(
                        "Nome" to u.nome,
                        "Profissão" to u.profissao,
                        "Coordenada" to u.coordenada
                    ))
            }

        }
    }
}